/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:03:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/08 12:21:00 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	(*g_printers[128])(t_data *data);

void		init_put(void)
{
	int	i;

	i = -1;
	while (++i < 127)
		g_printers[i] = &ft_invalid;
	g_printers['d'] = &ft_putnbr;
	g_printers['i'] = &ft_putnbr;
	g_printers['o'] = &ft_putnbr_o;
	g_printers['u'] = &ft_putunbr;
	g_printers['x'] = &ft_putnbr_x;
	g_printers['X'] = &ft_putnbr_xcaps;
	g_printers['c'] = &ft_putchar;
	g_printers['s'] = &ft_putstr;
	g_printers['p'] = &ft_putaddr;
	g_printers['%'] = &ft_putpercent;
}

void		fill_buffer(t_data *data, const char *s, int size)
{
	int	i;

	i = 0;
	if (data->i + size >= 100)
	{
		write(1, data->buffer, data->i);
		data->i = 0;
	}
	else
	{
		while (i < size)
		{
			data->buffer[data->i] = s[i];
			i++;
			data->i++;
		}
	}
}

void		init_buffer(t_data data)
{
	int	i;

	i = -1;
	while (++i < BUFF_SIZE)
		data.buffer[i] = '\0';
}

int			ft_printf(const char *restrict format, ...)
{
	int		i;
	int		c;
	t_data	data;

	i = 0;
	data.i = 0;
	init_buffer(data);
	va_start(data.ap, format);
	init_put();
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			data.format = format + i;
			c = format[i];
			g_printers[c](&data);
		}
		else
			fill_buffer(&data, format + i, 1);
		i++;
	}
	write(1, data.buffer, data.i);
	va_end(data.ap);
	return (0);
}
