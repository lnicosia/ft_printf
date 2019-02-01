/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:03:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/01 18:41:49 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	int		i;
	int		argc;
	va_list	ap;

	i = 0;
	argc = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i]);
		else
		{
			i++;
			if (format[i] == 'i' || format[i] == 'd')
			{
				ft_putnbr(va_arg(ap, long));
			}
			else if (format[i] == '%')
				ft_putchar('%');
			else if (format[i] == 'u' || format[i] == 'o' || format[i] == 'x'
					|| format[i] == 'X')
			{
				ft_putunbr(va_arg(ap, unsigned long));
			}
			else if (format[i] == 's')
			{
				ft_putstr(va_arg(ap, char *));
			}
			else if (format[i] == 'c')
			{
				ft_putchar(va_arg(ap, int));
			}
			if (format[i] == 'p')
			{
				ft_putnbr(va_arg(ap, long));
			}
			argc++;
		}
		i++;
	}
	va_end(ap);
	return (0);
}
