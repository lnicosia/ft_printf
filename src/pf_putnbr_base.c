/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 22:33:02 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/12 17:49:55 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_paddingx(t_data *data, unsigned long nb, int base_len)
{
	data->padding.size = data->sharp ? 2 : 0;
	if (nb == 0)
		data->padding.size = 1;
	while (nb != 0)
	{
		data->padding.size++;
		nb /= base_len;
	}
	data->padding.zeros = 0;
	if (data->prec > 0)
		data->padding.zeros = data->prec - data->padding.size;
	else if (!data->left && data->zero)
		data->padding.zeros = data->l_min - data->padding.size;
	if (data->padding.zeros < 0)
		data->padding.zeros = 0;
	data->padding.right_spaces = 0;
	data->padding.left_spaces = 0;
	if (data->left)
		data->padding.right_spaces = data->l_min - data->padding.zeros
			- data->padding.size;
	else
		data->padding.left_spaces = data->l_min - data->padding.zeros
			- data->padding.size;
}

static void	set_paddingo(t_data *data, unsigned long nb, int base_len)
{
	data->padding.size = data->sharp ? 1 : 0;
	if (nb == 0)
		data->padding.size = 1;
	while (nb != 0)
	{
		data->padding.size++;
		nb /= base_len;
	}
	data->padding.zeros = 0;
	if (data->prec > 0)
		data->padding.zeros = data->prec - data->padding.size;
	else if (!data->left && data->zero)
		data->padding.zeros = data->l_min - data->padding.size;
	if (data->padding.zeros < 0)
		data->padding.zeros = 0;
	data->padding.right_spaces = 0;
	data->padding.left_spaces = 0;
	if (data->left)
		data->padding.right_spaces = data->l_min - data->padding.zeros
			- data->padding.size;
	else
		data->padding.left_spaces = data->l_min - data->padding.zeros
			- data->padding.size;
}

void	pf_putnbr_x(t_data *data)
{
	unsigned long	nb;

	nb = va_arg(data->ap, unsigned long);
	if (data->size == 1)
		nb = (unsigned char)nb;
	else if (data->size == 2)
		nb = (unsigned short)nb;
	else if (data->size == 4)
		nb = (unsigned int)nb;
	set_paddingx(data, nb, 16);
	while (data->padding.left_spaces > 0)
	{
		fill_buffer(data, " ", 1);
		data->padding.left_spaces--;
	}
	if (data->sharp && nb)
		fill_buffer(data, "0x", 2);
	while (data->padding.zeros > 0)
	{
		fill_buffer(data, "0", 1);
		data->padding.zeros--;
	}
	pf_putlong_base(nb, "0123456789abcdef", data);
	while (data->padding.right_spaces > 0)
	{
		fill_buffer(data, " ", 1);
		data->padding.right_spaces--;
	}
}

void	pf_putnbr_xcaps(t_data *data)
{
	unsigned long	nb;

	nb = va_arg(data->ap, unsigned long);
	if (data->size == 1)
		nb = (unsigned char)nb;
	else if (data->size == 2)
		nb = (unsigned short)nb;
	else if (data->size == 4)
		nb = (unsigned int)nb;
	set_paddingx(data, nb, 16);
	while (data->padding.left_spaces > 0)
	{
		fill_buffer(data, " ", 1);
		data->padding.left_spaces--;
	}
	if (data->sharp && nb)
		fill_buffer(data, "0X", 2);
	while (data->padding.zeros > 0)
	{
		fill_buffer(data, "0", 1);
		data->padding.zeros--;
	}
	pf_putlong_base(nb, "0123456789ABCDEF", data);
	while (data->padding.right_spaces > 0)
	{
		fill_buffer(data, " ", 1);
		data->padding.right_spaces--;
	}
}

void	pf_putnbr_o(t_data *data)
{
	unsigned long	nb;

	nb = va_arg(data->ap, unsigned long);
	if (data->size == 1)
		nb = (unsigned char)nb;
	else if (data->size == 2)
		nb = (unsigned short)nb;
	else if (data->size == 4)
		nb = (unsigned int)nb;
	set_paddingo(data, nb, 8);
	while (data->padding.left_spaces > 0)
	{
		fill_buffer(data, " ", 1);
		data->padding.left_spaces--;
	}
	if (data->sharp && nb)
		fill_buffer(data, "0", 1);
	while (data->padding.zeros > 0)
	{
		fill_buffer(data, "0", 1);
		data->padding.zeros--;
	}
	pf_putlong_base(nb, "01234567", data);
	while (data->padding.right_spaces > 0)
	{
		fill_buffer(data, " ", 1);
		data->padding.right_spaces--;
	}
}
