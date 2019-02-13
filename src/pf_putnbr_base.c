/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 22:33:02 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/13 18:12:00 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "put_padding.h"

static void	set_padding(t_data *data, unsigned long nb, int base_len)
{
	if (nb == 0 && data->prec != 0)
		data->padding.size = 1;
	while (nb != 0)
	{
		data->padding.size++;
		nb /= base_len;
	}
	data->padding.zeros = 0;
	if (data->prec != -1)
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

static unsigned long	cast(t_data *data)
{
	unsigned long	nb;

	nb = va_arg(data->ap, unsigned long);
	if (data->size == 1)
		nb = (unsigned char)nb;
	else if (data->size == 2)
		nb = (unsigned short)nb;
	else if (data->size == 4)
		nb = (unsigned int)nb;
	return (nb);
}

void					pf_putnbr_x(t_data *data)
{
	unsigned long	nb;

	nb = cast(data);
	data->padding.size = (data->sharp && data->prec == -1) ? 2 : 0;
	set_padding(data, nb, 16);
	put_left_spaces(data);
	if (data->sharp && nb)
		fill_buffer(data, "0x", 2);
	put_zeros(data);
	if (nb != 0 || data->prec != 0)
		pf_putlong_base(nb, "0123456789abcdef", data);
	put_right_spaces(data);
}

void					pf_putnbr_xcaps(t_data *data)
{
	unsigned long	nb;

	nb = cast(data);
	data->padding.size = data->sharp ? 2 : 0;
	set_padding(data, nb, 16);
	put_left_spaces(data);
	if (data->sharp && nb)
		fill_buffer(data, "0X", 2);
	put_zeros(data);
	if (nb != 0 || data->prec != 0)
		pf_putlong_base(nb, "0123456789ABCDEF", data);
	put_right_spaces(data);
}

void					pf_putnbr_o(t_data *data)
{
	unsigned long	nb;

	nb = cast(data);
	data->padding.size = data->sharp ? 1 : 0;
	set_padding(data, nb, 8);
	put_left_spaces(data);
	if (data->sharp || (nb == 0 && data->prec != 0))
		fill_buffer(data, "0", 1);
	put_zeros(data);
	if (nb != 0)
		pf_putlong_base(nb, "01234567", data);
	put_right_spaces(data);
}
