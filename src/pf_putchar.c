/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:42:42 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/11 18:30:19 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_padding(t_data *data, char c)
{
	data->padding.size = 1;
	if (!data->left && data->zero)
		data->padding.zeros = data->l_min - data->padding.size;
	data->padding.right_spaces = 0;
	data->padding.left_spaces = 0;
	if (data->left)
		data->padding.right_spaces = data->l_min - data->padding.zeros
			- data->padding.size;
	else
		data->padding.left_spaces = data->l_min - data->padding.zeros
			- data->padding.size;
}

void		pf_putchar(t_data *data)
{
	char	c;

	c = va_arg(data->ap, int);
	set_padding(data, c);
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
	fill_buffer(data, &c, 1);
	while (data->padding.right_spaces > 0)
	{
		fill_buffer(data, " ", 1);
		data->padding.right_spaces--;
	}
}
