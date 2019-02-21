/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:40:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/21 11:38:41 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	parse_options(const char *s, int *i, t_data *data)
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

static void	parse_l_min(const char *s, int *i, t_data *data)
{
	int	nb;

	if (s[*i] >= '1' && s[*i] <= '9')
	{
		nb = pf_atoi(s + *i);
		data->l_min = nb;
		while (s[*i] >= '0' && s[*i] <= '9')
			(*i)++;
	}
}

static void parse_prec(const char *s, int *i, t_data *data)
{
	int	nb;

	while (s[*i] == '.')
		(*i)++;
	if (s[*i] >= '0' && s[*i] <= '9')
	{
		nb = pf_atoi(s + *i);
		data->prec = nb;
		while (s[*i] >= '0' && s[*i] <= '9')
			(*i)++;
	}
	else
		data->prec = 0;
}

static void	parse_size(const char *s, int *i, t_data *data)
{
	int	l;
	int	h;
	int	L;

	l = 0;
	h = 0;
	L = 0;
	while (s[*i] == 'l' || s[*i] == 'h' || s[*i] == 'z' || s[*i] == 'j'
			|| s[*i] == 'L')
	{
		if (s[*i] == 'l')
			l++;
		else if (s[*i] == 'h')
			h++;
		else if (s[*i] == 'L')
			L++;
		(*i)++;
	}
	if (l == 0 && h == 0)
		data->size = 4;
	else if (l >= 1)
		data->size = 8;
	else if (h == 1)
		data->size = 2;
	else if (h == 2)
		data->size = 1;
	if (L >= 1)
		data->size = 16;
}

char	parse_flags(const char *s, int *i, t_data *data)
{
	while (s[*i] == 'l' || s[*i] == 'h' || s[*i] == 'z' || s[*i] == 'j'
			|| s[*i] == '.' || s[*i] == '-' || s[*i] == '+' || s[*i] == '#'
			|| s[*i] == ' ' || (s[*i] >= '0' && s[*i] <= '9') || s[*i] == 'L')
	{
		if (s[*i] == '-' || s[*i] == '+' || s[*i] == '#' || s[*i] == ' '
			|| s[*i] == '0')
			parse_options(s, i, data);
		if (s[*i] >= '1' && s[*i] <= '9')
			parse_l_min(s, i, data);
		if (s[*i] == '.')
			parse_prec(s, i, data);
		if (s[*i] == 'l' || s[*i] == 'h' || s[*i] == 'z' || s[*i] == 'j'
			|| s[*i] == 'L')
			parse_size(s, i, data);
	}
	if (s[*i] != 'd' && s[*i] != 'i' && s[*i] != 'o' && s[*i] != 'u'
			&& s[*i] != 'x' && s[*i] != 'X' && s[*i] != 'f' && s[*i] != 'c'
			&& s[*i] != 's' && s[*i] != 'p' && s[*i] != '%' && s[*i] != 'O'
			&& s[*i] != 'U' && s[*i] != 'D' && s[*i] != 'C' && s[*i] != 'S'
			&& s[*i] != 'F' && s[*i] != 'b')
	{
		data->invalid = s + *i;
		if (s[*i] == '\0')
			(*i)--;
		return (0);
	}
	return (s[*i]);
}
