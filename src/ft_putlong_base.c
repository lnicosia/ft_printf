/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:18:56 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/08 12:19:51 by lnicosia         ###   ########.fr       */
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

void	ft_print(long nbr, int len, char *base, t_data *data)
{
	if (nbr < len)
		fill_buffer(data, &base[nbr], 1);
	else
	{
		ft_print((nbr) / len, len, base, data);
		ft_print((nbr) % len, len, base, data);
	}
}

void	ft_putlong_base(long nbr, char *base, t_data *data)
{
	int	len;
	int	min_stock;

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
			fill_buffer(data, "-", 1);
			nbr = -nbr;
		}
		ft_print(nbr, len, base, data);
		if (min_stock != -1)
			fill_buffer(data, &base[min_stock % len], 1);
	}
}
