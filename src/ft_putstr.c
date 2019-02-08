/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:07:40 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/08 12:11:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(t_data *data)
{
	int			i;
	const char	*s;

	s = va_arg(data->ap, char *);
	i = 0;
	while (s[i])
		i++;
	fill_buffer(data, s, i);
}
