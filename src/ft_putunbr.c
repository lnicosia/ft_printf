/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:09:15 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/01 20:34:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(t_data data)
{
	unsigned long nb;

	nb = data.unb;
	if (nb == 2147483648)
	{
		ft_putstr("-2");
		nb = 147483648;
	}
	if (nb < 10)
	{
		ft_putchar('0' + nb);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
