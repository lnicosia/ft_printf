/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:05:57 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/08 11:54:51 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddr(t_data *data)
{
	long a;

	a = (long)va_arg(data->ap, void *);
	fill_buffer(data, "0x", 2);
	ft_putlong_base(a, "0123456789abcdef", data);
}
