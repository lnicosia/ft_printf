/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:07:40 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/13 16:21:04 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "put_padding.h"

int			ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static void	set_padding(t_data *data, const char *s)
{
	data->padding.size = ft_strlen(s);
	data->padding.zeros = 0;
	if (data->prec >= 0 && data->prec < data->padding.size)
		data->padding.size = data->prec;
	if (!data->left && data->zero)
		data->padding.zeros = data->l_min - data->padding.size;
	data->padding.right_spaces = 0;
	data->padding.left_spaces = 0;
	if (data->left && data->l_min > 1)
		data->padding.right_spaces = data->l_min - data->padding.zeros
			- data->padding.size;
	else if (data->l_min > 1)
		data->padding.left_spaces = data->l_min - data->padding.zeros
			- data->padding.size;
}

void	pf_putstr(t_data *data)
{
	const char	*s;

	s = va_arg(data->ap, char *);
	if (s == NULL && data->l_min == 0)
	{
		fill_buffer(data, "(null)", 6);
		return ;
	}
	set_padding(data, s);
	put_left_spaces(data);
	put_zeros(data);
	fill_buffer(data, s, data->padding.size);
	put_right_spaces(data);
}
