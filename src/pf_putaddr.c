/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:05:57 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/13 13:53:12 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "put_padding.h"

static void	set_paddingx(t_data *data, long nb, int base_len)
{
	data->padding.size = nb == 0 ? 3 : 2;
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

void	pf_putaddr(t_data *data)
{
	long	nb;

	nb = va_arg(data->ap, long);
	set_paddingx(data, nb, 16);
	put_left_spaces(data);
	fill_buffer(data, "0x", 2);
	put_zeros(data);
	pf_putlong_base(nb, "0123456789abcdef", data);
	put_right_spaces(data);
}
