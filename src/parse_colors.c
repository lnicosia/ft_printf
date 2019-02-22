/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:03:19 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/22 14:36:23 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "color.h"

void	parse_color(const char *s, int *i, t_data *data)
{
	if (pf_strnequ(s + *i, "{{", 2) == 1)
	{
		fill_buffer(data, s + *i, 1);
		(*i)++;
	}
	else if (pf_strnequ(s + *i, "{red}", 5) == 1)
	{
		fill_buffer(data, RED, 7);
		(*i) += 4;
	}
	else if (pf_strnequ(s + *i, "{green}", 7) == 1)
	{
		fill_buffer(data, GREEN, 7);
		(*i) += 6;
	}
	else if (pf_strnequ(s + *i, "{cyan}", 6) == 1)
	{
		fill_buffer(data, CYAN, 7);
		(*i) += 5;
	}
	else if (pf_strnequ(s + *i, "{reset}", 7) == 1)
	{
		fill_buffer(data, RESET, 4);
		(*i) += 6;
	}
	else if (pf_strnequ(s + *i, "{yellow}", 8) == 1)
	{
		fill_buffer(data, YELLOW, 7);
		(*i) += 7;
	}
	else if (pf_strnequ(s + *i, "{blue}", 6) == 1)
	{
		fill_buffer(data, BLUE, 7);
		(*i) += 5;
	}
	else if (pf_strnequ(s + *i, "{magenta}", 9) == 1)
	{
		fill_buffer(data, MAGENTA, 7);
		(*i) += 8;
	}
}
