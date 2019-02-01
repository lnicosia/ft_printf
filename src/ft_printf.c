/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:03:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/01 20:36:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	(*put[128])(t_data data);

void		init_put(void)
{
	put['i'] = (&ft_putnbr);
	put['d'] = (&ft_putnbr);
	put['u'] = (&ft_putunbr);
}

int			ft_printf(const char *restrict format, ...)
{
	int		i;
	int		argc;
	va_list	ap;
	t_data	data;

	i = 0;
	argc = 0;
	va_start(ap, format);
	init_put();
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i]);
		else
		{
			i++;
			if (format[i] == 'i' || format[i] == 'd')
			{
				data.nb = va_arg(ap, long);
			}
			else if (format[i] == '%')
				ft_putchar('%');
			else if (format[i] == 'u')
			{
				ft_putunbr(va_arg(ap, unsigned long));
			}
			else if (format[i] == 'x')
			{
				ft_putnbr_base(va_arg(ap, long), "0123456789abcdef");
			}
			else if (format[i] == 'X')
			{
				ft_putnbr_base(va_arg(ap, long), "0123456789ABCDEF");
			}
			else if (format[i] == 'o')
			{
				ft_putnbr_base(va_arg(ap, long), "01234567");
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
				ft_putaddr(va_arg(ap, void *));
			}
			argc++;
		}
		i++;
	}
	va_end(ap);
	return (0);
}
