/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:01:05 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/11 17:03:44 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# define BUFF_SIZE 100

typedef struct	s_padding
{
	int	left_spaces;
	int	sign;
	int	zeros;
	int	size;
	int	right_spaces;
}				t_padding;

typedef struct	s_data
{
	va_list		ap;
	const char	*options;
	char		buffer[BUFF_SIZE];
	int			i;
	int			left;
	int			plus;
	int			zero;
	int			space;
	int			sharp;
	int			l_min;
	int			prec;
	int			size;
	t_padding	padding;
}				t_data;

int		ft_printf(const char *restrict format, ...);
void	pf_putchar(t_data *data);
void	pf_putnbr(t_data *data);
void	pf_putunbr(t_data *data);
void	pf_putstr(t_data *data);
void	pf_putaddr(t_data *data);
void	pf_putnbr_x(t_data *data);
void	pf_putnbr_xcaps(t_data *data);
void	pf_putnbr_o(t_data *data);
void	pf_putlong_base(long nbr, char *base, t_data *data);
void	pf_invalid(t_data *data);
void	pf_putpercent(t_data *data);
void	fill_buffer(t_data *data, const char *s, int size);
char	parse_flags(const char *s, int *i, t_data *data);
int		pf_atoi(const char *str);
void	reset_options(t_data *data);

#endif
