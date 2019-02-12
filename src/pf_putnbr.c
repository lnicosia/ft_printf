/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:09:15 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/12 17:17:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_putlong(long nb, t_data *data)
{
	char	c;

	if (nb > 0)
		nb = -nb;
	if (nb > -10)
	{
		c = '0' - nb;
		fill_buffer(data, &c, 1);
	}
	else
	{
		pf_putlong(nb / 10, data);
		pf_putlong(nb % 10, data);
	}
}

void		print_sign(t_data *data, long *nb)
{
	if (*nb < 0)
		fill_buffer(data, "-", 1);
	else if (data->plus)
		fill_buffer(data, "+", 1);
	else if (data->space)
		fill_buffer(data, " ", 1);
}

static void	set_padding(t_data *data, long nb)
{
	data->padding.size = 0;
	data->padding.sign = (nb < 0 || data->plus || data->space) ? 1 : 0;
	if (nb == 0)
		data->padding.size = 1;
	while (nb != 0)
	{
		data->padding.size++;
		nb /= 10;
	}
	data->padding.zeros = 0;
	if (data->prec > 0)
		data->padding.zeros = data->prec - data->padding.size;
	else if (!data->left && data->zero)
		data->padding.zeros = data->l_min - data->padding.size
			- data->padding.sign;
	if (data->padding.zeros < 0)
		data->padding.zeros = 0;
	data->padding.right_spaces = 0;
	data->padding.left_spaces = 0;
	if (data->left)
		data->padding.right_spaces = data->l_min - data->padding.sign
			- data->padding.zeros - data->padding.size;
	else
		data->padding.left_spaces = data->l_min - data->padding.sign
			- data->padding.zeros - data->padding.size;
}

void		pf_putnbr(t_data *data)
{
	long	nb;

	nb = va_arg(data->ap, long);
	if (data->size == 1)
		nb = (char)nb;
	else if (data->size == 2)
		nb = (short)nb;
	else if (data->size == 4)
		nb = (int)nb;
	set_padding(data, nb);
	while (data->padding.left_spaces > 0)
	{
		fill_buffer(data, " ", 1);
		data->padding.left_spaces--;
	}
	if (data->padding.sign)
	{
		if (nb < 0)
			fill_buffer(data, "-", 1);
		else if (data->plus)
			fill_buffer(data, "+", 1);
		else if (data->space)
			fill_buffer(data, " ", 1);
	}
	while (data->padding.zeros > 0)
	{
		fill_buffer(data, "0", 1);
		data->padding.zeros--;
	}
	pf_putlong(nb, data);
	while (data->padding.right_spaces > 0)
	{
		fill_buffer(data, " ", 1);
		data->padding.right_spaces--;
	}
}
