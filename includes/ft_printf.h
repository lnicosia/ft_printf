/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:01:05 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/01 20:35:16 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_data
{
	long			nb;
	unsigned long	unb;
	char			*s;
}				t_data;

int		ft_printf(const char *restrict format, ...);
void	ft_putchar(t_data data);
void	ft_putnbr(t_data data);
void	ft_putunbr(t_data data);
void	ft_putstr(t_data data);
void	ft_putaddr(t_data data);
void	ft_putnbr_base(t_data data);

#endif
