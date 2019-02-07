/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:01:05 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/07 16:51:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_data
{
	va_list			ap;
	long			l;
	unsigned long	ul;
	const char		*s;
	const char		*format;
	char			c;
	void			*p;
}				t_data;

int		ft_printf(const char *restrict format, ...);
void	ft_putchar(t_data *data);
void	ft_putnbr(t_data *data);
void	ft_putunbr(t_data *data);
void	ft_putstr(t_data *data);
void	ft_putaddr(t_data *data);
void	ft_putnbr_x(t_data *data);
void	ft_putnbr_X(t_data *data);
void	ft_putnbr_o(t_data *data);
void	ft_putlong_base(long nbr, char *base);
void	ft_invalid(t_data *data);
void	ft_putpercent(t_data *data);

#endif
