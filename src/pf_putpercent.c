/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpercent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:22:53 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/12 17:18:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_padding(t_data *data)
{
	data->padding.zeros = 0;
	if (data->prec > 0)
		data->padding.zeros = data->prec - 1;
	else if (!data->left && data->zero)
		data->padding.zeros = data->l_min - 1;
	if (data->padding.zeros < 0)
		data->padding.zeros = 0;
	data->padding.right_spaces = 0;
	data->padding.left_spaces = 0;
	if (data->left)
		data->padding.right_spaces = data->l_min - data->padding.zeros - 1;
	else
		data->padding.left_spaces = data->l_min	- data->padding.zeros - 1;
}

void	pf_putpercent(t_data *data)
{
	set_padding(data);
	while (data->padding.left_spaces > 0)
	{
		fill_buffer(data, " ", 1);
		data->padding.left_spaces--;
	}
	while (data->padding.zeros > 0)
	{
		fill_buffer(data, "0", 1);
		data->padding.zeros--;
	}
	fill_buffer(data, "%", 1);
	while (data->padding.right_spaces > 0)
	{
		fill_buffer(data, " ", 1);
		data->padding.right_spaces--;
	}
}
