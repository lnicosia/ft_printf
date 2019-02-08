/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:09:15 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/08 11:54:36 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlong(long nb, t_data *data)
{
	char	c;

	if (nb < 0)
	{
		nb = -nb;
		fill_buffer(data, "-", 1);
	}
	if (nb < 10)
	{
		c = '0' + nb;
		fill_buffer(data, &c, 1);
	}
	else
	{
		ft_putlong(nb / 10, data);
		ft_putlong(nb % 10, data);
	}
}

void	ft_putnbr(t_data *data)
{
	ft_putlong(va_arg(data->ap, long), data);
}
