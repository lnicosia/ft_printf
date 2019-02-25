/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:35:58 by gaerhard          #+#    #+#             */
/*   Updated: 2019/02/22 18:38:58 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "put_padding.h"
#include <stdlib.h>

static void	put_sign_float(t_data *data, long double nb)
{
	if (data->padding.sign)
	{
		if (nb < 0 || 1.0 / nb < 0)
		{
			fill_buffer(data, "-", 1);
		}
		else if (data->plus)
			fill_buffer(data, "+", 1);
		else if (data->space)
			fill_buffer(data, " ", 1);
	}
}

static long double cast_float(t_data *data)
{
	long double nb;

	if (data->size == 16)
		nb = va_arg(data->ap, long double);
	else
		nb = va_arg(data->ap, double);
	return (nb);
}






int		pf_ftoa(t_data *data, long nb, int precision)
{
	int		i;
	char	*str;

	if (!(str = pf_strnew(precision, data)))
		return (-1);
	i = 0;
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	while (i < precision)
		str[i++] = '0';
	rev_str(str, i);
	str[i++] = '\0';
	fill_buffer(data, str, precision);
	pf_strdel(&str);
	return (i);
}

int		pf_itoa(t_data *data, long nb)
{
	int		i;
	int		size;
	char	*str;

	size = get_size(nb);
	if (nb == 0)
	{
		fill_buffer(data, "0", 1);
		return (1);
	}
	nb = (nb > 0) ? -nb : nb;
	if (!(str = pf_strnew(size, data)))
		return (-1);
	i = 0;
	while (nb < 0)
	{
		str[i++] = '0' - (nb % 10);
		nb = nb / 10;
	}
	rev_str(str, i);
	fill_buffer(data, str, size);
	pf_strdel(&str);
	return (i + 1);
}

static void	set_padding_lmin(t_data *data)
{
	if (!data->left)
	{
		if (data->zero)
			data->padding.zeros = data->l_min - data->padding.size;
		else
			data->padding.left_spaces = data->l_min - data->padding.size;
	}
	else
		data->padding.right_spaces = data->l_min - data->padding.size;
}

static void	set_padding(t_data *data, long i_part, long double nb)
{
	data->padding.size = (data->prec > 0) ? data->prec + 1 : data->prec;
	if (i_part == 0)
		data->padding.size++;
	if (data->sharp)
		data->padding.size++;
	if (data->plus || data->space || nb < 0 || 1.0 / nb < 0)
	{
		data->padding.sign = 1;
		data->padding.size++;
	}
	while (i_part != 0)
	{
		data->padding.size++;
		i_part /= 10;
	}
	data->padding.left_spaces = 0;
	data->padding.right_spaces = 0;
	if (data->l_min > data->padding.size)
		set_padding_lmin(data);
}

static void	set_padding_inf(t_data *data, long double nb)
{
	data->padding.size = (nb == -1.0 / 0.0) ? 3 : 3;
	if (data->plus || data->space || nb == -1.0 / 0.0)
	{
		data->padding.sign = 1;
		data->padding.size++;
	}
	data->padding.left_spaces = 0;
	data->padding.right_spaces = 0;
	if (!data->left)
		data->padding.left_spaces = data->l_min - data->padding.size;
	else
		data->padding.right_spaces = data->l_min - data->padding.size;
}

static int	inf(t_data *data, long double nb)
{
	if (nb == 1.0 / 0.0 || nb == -1.0 / 0.0 || nb != nb)
	{
		set_padding_inf(data, nb);
		put_left_spaces(data);
		if (nb == -1.0 / 0.0)
			fill_buffer(data, "-", 1);
		else if (data->plus)
			fill_buffer(data, "+", 1);
		else if (data->space)
			fill_buffer(data, " ", 1);
		put_zeros(data);
		if (nb == -1.0 / 0.0)
			fill_buffer(data, "inf", 3);
		else if (nb == 1.0 / 0.0)
			fill_buffer(data, "inf", 3);
		else
			fill_buffer(data, "nan", 3);
		put_right_spaces(data);
		return (-1);
	}
	return (1);
}

long double	pf_ipart(t_data *data, long double nb)
{
	long i_part;

	i_part = (long)nb;
	set_padding(data, i_part, nb);
	put_left_spaces(data);
	put_sign_float(data, nb);
	put_zeros(data);
	return ((long double)i_part);
}

void	pf_putfloat(t_data *data)
{
	long double		nb;
	long double		f_part;

	nb = cast_float(data);
	if (inf(data, nb) == -1)
		return ;
	data->prec = (data->prec == -1) ? 6 : data->prec;
	if (data->prec == 0 && nb != 0)
		nb += (nb < 0) ? -0.4999999 : 0.4999999;
	f_part = pf_ipart(data, nb);
	if ((pf_itoa(data, f_part)) == -1)
		return ;
	f_part = nb - f_part;
	if (data->prec != 0 || data->sharp)
		fill_buffer(data, ".", 1);
	if (data->prec != 0)
	{
		f_part = (f_part < 0) ? -f_part : f_part;
		f_part = f_part * power(10, data->prec) + 0.5;
		if ((pf_ftoa(data, f_part, data->prec)) == -1)
			return ;
	}
	put_right_spaces(data);
}
