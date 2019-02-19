/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:35:58 by gaerhard          #+#    #+#             */
/*   Updated: 2019/02/19 17:39:37 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "put_padding.h"

static int	get_size(long nbr)
{
	int size;

	size = 0;
	if (nbr == 0)
		size++;
	while (nbr != 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

static long	power(long nb, int power)
{
	long tmp;

	tmp = nb;
	if (power == 0)
		return (1);
	if (power < 1)
		return (0);
	while (--power)
		nb *= tmp;
	return (nb);
}

char		*pf_strnew(int size)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

void	rev_str(char *str, int len) 
{ 
	int		i;
	char	tmp;

	i = 0; 
	while (i < len)
	{ 
		tmp = str[i]; 
		str[i] = str[len - 1]; 
		str[len - 1] = tmp;
		i++;
		len--; 
	} 
}

int		pf_ftoa(t_data *data, long nb, int precision)
{
	int		i;
	char	*str;

	if (!(str = pf_strnew(precision)))
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
	free(str);
	str = NULL;
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
	if (nb > 0)
		nb = -nb;
	if (!(str = pf_strnew(size)))
		return (-1);
	i = 0;
	while (nb < 0)
	{
		str[i] = '0' - (nb % 10);
		nb = nb / 10;
		i++;
	}
	rev_str(str, i);
	str[i++] = '\0';
	fill_buffer(data, str, size);
	free(str);
	str = NULL;
	return (i);
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
	if (data->l_min > data->padding.size/* && data->prec == 0*/)
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

static void	inf(t_data *data, long double nb)
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
}

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

void	pf_putfloat(t_data *data)
{
	int				i;
	long			i_part;
	long double		nb;
	double			f_part;

	nb = va_arg(data->ap, double);
	//printf("nb = %Lf\n", nb);
	if (nb == 1.0 / 0.0 || nb == -1.0 / 0.0 || nb != nb)
	{
		inf(data, nb);
		return ;
	}
	else
		data->padding.size = 0;
	if (data->prec == -1)
		data->prec = 6;
	if (data->prec == 0 && nb != 0)
		nb += (nb < 0) ? -0.4999999 : 0.4999999;
	//printf("prec = %d\n", data->prec);
	i_part = (long)nb;
	f_part = nb - (double)i_part;
	//printf("f_part%f\n", f_part);
	set_padding(data, i_part, nb);
	put_left_spaces(data);
	put_sign_float(data, nb);
	put_zeros(data);
	if ((i = pf_itoa(data, i_part)) == -1)
		return ;
	if (data->prec != 0 || data->sharp)
		fill_buffer(data, ".", 1);
	if (data->prec != 0)
	{
		f_part = (f_part < 0) ? -f_part : f_part;
		//printf("f_part%f\n", f_part);
		f_part = f_part * power(10, data->prec) + 0.5;
		//printf("f_part%f\n", f_part);
		if ((i = pf_ftoa(data, (long)f_part, data->prec)) == -1)
			return ;
		while (i++ < data->prec)
			fill_buffer(data, "0", 1);
	}
	put_right_spaces(data);
}
