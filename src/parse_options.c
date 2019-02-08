/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:40:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/08 18:42:24 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	parse_options(const char *s, int *i, t_data *data)
{
	int	nb;

	data->options = s;
	if (s[*i] == '-')
	{
		data->left = 1;
		(*i)++;
	}
	if (s[*i] == '0')
	{
		data->zero = 1;
		(*i)++;
	}
	if (s[*i] >= '1' && s[*i] <= '9')
	{
		nb = pf_atoi(s + *i);
		data->l_min = nb;
		while (nb != 0)
		{
			(*i)++;
			nb /= 10;
		}
	}
	if (s[*i] == 'l')
	{
		data->size = 8;
		(*i)++;
		if (s[*i] == 'l')
			(*i)++;
	}
	else if (s[*i] == 'h')
	{
		(*i)++;
		if (s[*i] == 'h')
		{
			data->size = 1;
			(*i)++;
		}
		else
			data->size = 2;
	}
	else
		data->size = 4;
	return (s[*i]);
}
