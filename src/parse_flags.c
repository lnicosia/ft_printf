/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:40:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/12 20:23:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	parse_options(const char *s, int *i, t_data *data)
{
	while (s[*i] == '-' || s[*i] == '+' || s[*i] == '#' || s[*i] == ' '
			|| s[*i] == '0')
	{
		if (s[*i] == '-')
			data->left = 1;
		else if (s[*i] == '+')
			data->plus = 1;
		else if (s[*i] == ' ')
			data->space = 1;
		else if (s[*i] == '#')
			data->sharp = 1;
		else if (s[*i] == '0')
			data->zero = 1;
		(*i)++;
	}
}

char	parse_flags(const char *s, int *i, t_data *data)
{
	int	nb;

	data->options = s;
	parse_options(s, i, data);
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
	if (s[*i] == '.')
	{
		(*i)++;
		nb = pf_atoi(s + *i);
		data->prec = nb;
		if (nb == 0)
			(*i)++;
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
		data->size = 2;
		(*i)++;
		if (s[*i] == 'h')
		{
			data->size = 1;
			(*i)++;
		}
	}
	else
		data->size = 4;
	if (s[*i] != 'd' && s[*i] != 'i' && s[*i] != 'o' && s[*i] != 'u'
			&& s[*i] != 'x' && s[*i] != 'X' && s[*i] != 'f' && s[*i] != 'c'
			&& s[*i] != 's' && s[*i] != 'p' && s[*i] != '%' && s[*i] != 'O'
			&& s[*i] != 'U' && s[*i] != 'D')
	{
		data->invalid = s + *i;
		if (s[*i] == '\0')
			(*i)--;
		return (0);
	}
	return (s[*i]);
}
