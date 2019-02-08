/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:09:15 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/08 16:53:24 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_putulong(long nb, t_data *data)
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
		pf_putulong(nb / 10, data);
		pf_putulong(nb % 10, data);
	}
}

void	pf_putunbr(t_data *data)
{
	pf_putulong(va_arg(data->ap, long), data);
}
