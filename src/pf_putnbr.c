/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:09:15 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/08 18:47:34 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_putlong(long nb, t_data *data)
{
	char	c;

	if (nb == -9223372036854775808)
	{
		fill_buffer(data, "-9223372036854775808", 20);
		return ;
	}
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
		pf_putlong(nb / 10, data);
		pf_putlong(nb % 10, data);
	}
}

void	pf_putnbr(t_data *data)
{
	long	nb;
	long	tmp;
	int		size;

	nb = (long)va_arg(data->ap, long);
	size = nb < 0 ? 1 : 0;
	tmp = nb;
	while (tmp != 0)
	{
		size++;
		tmp /= 10;
	}
	printf("size = %d\n", size);
	printf("l_min = %d\n", data->l_min);
	while (size < data->l_min)
	{
		fill_buffer(data, " ", 1);
		size++;
	}
	if (data->size == 1)
		pf_putlong((char)nb, data);
	else if (data->size == 2)
		pf_putlong((short)nb, data);
	else if (data->size == 4)
		pf_putlong((int)nb, data);
	else
		pf_putlong(nb, data);
	data->size = 4;
	data->l_min = 1;
}
