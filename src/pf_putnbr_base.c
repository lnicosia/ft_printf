/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 22:33:02 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/08 16:50:05 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putnbr_x(t_data *data)
{
	pf_putlong_base(va_arg(data->ap, long), "0123456789abcdef", data);
}

void	pf_putnbr_xcaps(t_data *data)
{
	pf_putlong_base(va_arg(data->ap, long), "0123456789ABCDEF", data);
}

void	pf_putnbr_o(t_data *data)
{
	pf_putlong_base(va_arg(data->ap, long), "01234567", data);
}
