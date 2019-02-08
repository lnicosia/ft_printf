/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 22:33:02 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/08 12:20:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_x(t_data *data)
{
	ft_putlong_base(va_arg(data->ap, long), "0123456789abcdef", data);
}

void	ft_putnbr_xcaps(t_data *data)
{
	ft_putlong_base(va_arg(data->ap, long), "0123456789ABCDEF", data);
}

void	ft_putnbr_o(t_data *data)
{
	ft_putlong_base(va_arg(data->ap, long), "01234567", data);
}
