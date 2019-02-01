/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 22:33:02 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/01 20:32:41 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] <= ' ' || base[i] > '~' || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_print(long nbr, int len, char *base)
{
	if (nbr < len)
		ft_putchar(base[nbr]);
	else
	{
		ft_print((nbr) / len, len, base);
		ft_print((nbr) % len, len, base);
	}
}

void	ft_putnbr_base(t_data data)
{
	int	nbr;
	int len;
	int min_stock;
	char *base;

	nbr = data.nb;
	base = t_data.s;
	len = ft_check_base(base);
	min_stock = -1;
	if (len > 1)
	{
		if (nbr == -2147483648)
		{
			min_stock = -(nbr % len);
			nbr = nbr / len;
		}
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		ft_print(nbr, len, base);
		if (min_stock != -1)
			ft_putchar(base[min_stock % len]);
	}
}
