/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:03:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/21 13:48:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	(*g_printers[128])(t_data *data);

void		init_put(void)
{
	int	i;

	i = -1;
	while (++i < 127)
		g_printers[i] = &pf_invalid;
	g_printers['d'] = &pf_putnbr;
	g_printers['D'] = &pf_putnbr;
	g_printers['i'] = &pf_putnbr;
	g_printers['o'] = &pf_putnbr_o;
	g_printers['b'] = &pf_putnbr_b;
	g_printers['O'] = &pf_putnbr_o;
	g_printers['u'] = &pf_putunbr;
	g_printers['U'] = &pf_putunbr;
	g_printers['x'] = &pf_putnbr_x;
	g_printers['X'] = &pf_putnbr_xcaps;
	g_printers['c'] = &pf_putchar;
	g_printers['C'] = &pf_putchar;
	g_printers['s'] = &pf_putstr;
	g_printers['S'] = &pf_putstr;
	g_printers['p'] = &pf_putaddr;
	g_printers['%'] = &pf_putpercent;
	g_printers['f'] = &pf_putfloat;
	g_printers['F'] = &pf_putfloat;
}

void		fill_buffer(t_data *data, const char *s, int size)
{
	int	i;

	i = 0;
	if (data->i + size >= BUFF_SIZE)
	{
		write(1, data->buffer, data->i);
		data->i = 0;
		data->ret += 100;
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

void		reset_options(t_data *data)
{
	data->left = 0;
	data->plus = 0;
	data->zero = 0;
	data->space = 0;
	data->sharp = 0;
	data->l_min = 0;
	data->prec = -1;
	data->size = 4;
	data->invalid = "\0";
	data->padding.size = 0;
	data->padding.zeros = 0;
}

void		init_buffer(t_data *data)
{
	int	i;

	i = -1;
	while (++i < BUFF_SIZE)
		data->buffer[i] = '\0';
	reset_options(data);
}

int			ft_printf(const char *restrict format, ...)
{
	int		i;
	int		c;
	t_data	data;

	if (!format)
		return (-1);
	i = 0;
	data.i = 0;
	data.ret = 0;
	init_buffer(&data);
	va_start(data.ap, format);
	init_put();
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			c = parse_flags(format, &i, &data);
			g_printers[c](&data);
		}
		else
			fill_buffer(&data, format + i, 1);
		reset_options(&data);
		i++;
	}
	write(1, data.buffer, data.i);
	data.ret += data.i;
	va_end(data.ap);
	return (data.ret);
}
