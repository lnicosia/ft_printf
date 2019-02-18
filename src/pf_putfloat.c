#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "put_padding.h"

static int	get_size(long nbr)
{
	int size;

	size = 0;
	if (nbr <= 0)
		size++;
	while (nbr != 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

static long	power(long nb, int power)
{
	long tmp;

	tmp = nb;
	if (power == 0)
		return (1);
	if (power < 1)
		return (0);
	while (--power)
		nb *= tmp;
	return (nb);
}

char		*pf_strnew(int size)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

void	rev_str(char *str, int len) 
{ 
	int		i;
	char	tmp;

	i = 0; 
	while (i < len)
	{ 
		tmp = str[i]; 
		str[i] = str[len - 1]; 
		str[len - 1] = tmp;
		i++;
		len--; 
	} 
}

int		pf_ftoa(t_data *data, long nb, int precision)
{
	int		i;
	char	*str;

	if (!(str = pf_strnew(precision)))
		return (-1);
	i = 0;
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	while (i < precision)
		str[i++] = '0';
	rev_str(str, i);
	str[i++] = '\0';
	fill_buffer(data, str, precision);
	free(str);
	str = NULL;
	return (i);
}

int		pf_itoa(t_data *data, long nb)
{
	int		i;
	int		size;
	char	*str;

	size = get_size(nb);
	if (nb == 0)
	{
		fill_buffer(data, "0", 1);
		return (1);
	}
	if (nb > 0)
		nb = -nb;
	if (!(str = pf_strnew(size)))
		return (-1);
	i = 0;
	while (nb < 0)
	{
		str[i] = '0' - (nb % 10);
		nb = nb / 10;
		i++;
	}
	rev_str(str, i);
	str[i++] = '\0';
	fill_buffer(data, str, size);
	free(str);
	str = NULL;
	return (i);
}

static void	set_padding(t_data *data, long i_part)
{
	int	size;

	size = 0;
	if (i_part == 0)
		size++;
	if (data->sharp)
		size++;
	if (data->plus || data->space || i_part < 0)
		size++;
	while (i_part != 0)
	{
		size++;
		i_part /= 10;
	}
	data->padding.left_spaces = 0;
	data->padding.right_spaces = 0;
	if (data->l_min > size && data->prec == 0)
	{
		if (!data->left)
		{
			if (data->zero)
				data->padding.zeros = data->l_min - size;
			else
				data->padding.left_spaces = data->l_min - size;
		}
		else
			data->padding.right_spaces = data->l_min - size;
	}
}

void	pf_putfloat(t_data *data)
{
	int				i;
	long			i_part;
	long double		nb;
	double			f_part;

	nb = va_arg(data->ap, double);
	//printf("nb = %lf\n", nb);
	if (data->prec == -1)
		data->prec = 6;
	//printf("prec = %d\n", data->prec);
	i_part = (long)nb;
	f_part = nb - (double)i_part;
	//printf("f_part%f\n", f_part);
	set_padding(data, i_part);
	put_left_spaces(data);
	put_zeros(data);
	put_sign(data, i_part);
	if ((i = pf_itoa(data, i_part)) == -1)
		return ;
	if (data->prec != 0 || data->sharp)
		fill_buffer(data, ".", 1);
	if (data->prec != 0)
	{
		f_part = (f_part < 0) ? -f_part : f_part;
		//printf("f_part%f\n", f_part);
		f_part = f_part * power(10, data->prec) + 0.5;
		//printf("f_part%f\n", f_part);
		if ((i = pf_ftoa(data, (long)f_part, data->prec)) == -1)
			return ;
		while (i++ < data->prec)
			fill_buffer(data, "0", 1);
	}
	put_right_spaces(data);
}
