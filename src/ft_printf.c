/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:03:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/07 17:31:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	(*put[128])(t_data *data);

void		init_put(void)
{
	int	i;

	i = -1;
	while (++i < 127)
		put[i] = &ft_invalid;
	put['i'] = &ft_putnbr;
	put['d'] = &ft_putnbr;
	put['u'] = &ft_putunbr;
	put['x'] = &ft_putnbr_x;
	put['X'] = &ft_putnbr_X;
	put['o'] = &ft_putnbr_o;
	put['s'] = &ft_putstr;
	put['c'] = &ft_putchar;
	put['p'] = &ft_putaddr;
	put['%'] = &ft_putpercent;
}

int			ft_printf(const char *restrict format, ...)
{
	int		i;
	int		argc;
	t_data	data;

	i = 0;
	argc = 0;
	va_start(data.ap, format);
	init_put();
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			data.format = format + i;
			put[(int)format[i]](&data);
		}
		else
			write(1, &format[i], 1);
			argc++;
		i++;
	}
	va_end(data.ap);
	return (0);
}
