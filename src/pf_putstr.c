/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:07:40 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/11 18:58:26 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	set_padding(t_data *data, const char *s)
{
	data->padding.size = ft_strlen(s);
	if (data->prec >= 0 && data->prec < data->padding.size)
		data->padding.size = data->prec;
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

void	pf_putstr(t_data *data)
{
	const char	*s;

	s = va_arg(data->ap, char *);
	set_padding(data, s);
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
	fill_buffer(data, s, data->padding.size);
	while (data->padding.right_spaces > 0)
	{
		fill_buffer(data, " ", 1);
		data->padding.right_spaces--;
	}
}