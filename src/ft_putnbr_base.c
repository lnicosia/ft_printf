/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 22:33:02 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/07 16:51:52 by lnicosia         ###   ########.fr       */
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
		write(1, &base[nbr], 1);
	else
	{
		ft_print((nbr) / len, len, base);
		ft_print((nbr) % len, len, base);
	}
}

void	ft_putlong_base(long nbr, char *base)
{
	int 	len;
	int 	min_stock;

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
			write(1, "-", 1);
			nbr = -nbr;
		}
		ft_print(nbr, len, base);
		if (min_stock != -1)
			write(1, &base[min_stock % len], 1);
	}
}

void	ft_putnbr_x(t_data *data)
{
	ft_putlong_base(va_arg(data->ap, long), "0123456789abcdef");
}

void	ft_putnbr_X(t_data *data)
{
	ft_putlong_base(va_arg(data->ap, long), "0123456789ABCDEF");
}

void	ft_putnbr_o(t_data *data)
{
	ft_putlong_base(va_arg(data->ap, long), "01234567");
}
