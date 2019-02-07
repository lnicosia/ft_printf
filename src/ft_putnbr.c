/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:09:15 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/07 16:33:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlong(long nb)
{
	char	c;

	if (nb < 0)
	{
		nb = -nb;
		write(1 , "-", 1);
	}
	if (nb < 10)
	{
		c = '0' + nb;
		write(1, &c, 1);
	}
	else
	{
		ft_putlong(nb / 10);
		ft_putlong(nb % 10);
	}
}

void	ft_putnbr(t_data *data)
{
	ft_putlong(va_arg(data->ap, long));
}
