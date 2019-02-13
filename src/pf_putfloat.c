#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

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

static int	power_over_nine_thousand(long nb, int power)
{
	int tmp;

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
	while (i < len - 1) 
	{ 
		tmp = str[i]; 
		str[i] = str[len]; 
		str[len] = tmp; 
		i++;
		len--; 
	} 
}

int		pf_itoa(t_data *data, long nb, int precision)
{
	int		i;
	int		size;
	char	*str;

	size = get_size(nb);
	if (!(str = pf_strnew(size)))
		return (-1);
	i = 0;
	while (nb)
	{
		str[i++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	while (i < precision)
		str[i++] = '0';
	rev_str(str, i);
	str[i] = '\0';
	fill_buffer(data, str, size);
	free(str);
	return (i);
}

void	pf_putfloat(t_data *data)
{
	int			i;
	long		i_part;
	long double	nb;
	double		f_part;

	nb = va_arg(data->ap, long double);
	i_part = (long)nb;
	f_part = nb - (double)i_part;
	i = pf_itoa(data, i_part, 0);
	if (data->prec != 0)
	{
		fill_buffer(data, ".", 1);
		f_part = f_part * power_over_nine_thousand(10, data->prec);
		printf("f_part %d\n", (int)(f_part + 0.5));
		pf_itoa(data, (int)f_part, data->prec);
	}
}
/*
int	main(void)
{
	char *str;

	printf("15.36: %.2f\n", 15.36);
	printf("1.5123: %f\n", 1.5123);
	printf("1.5123456789: %.7lf\n", 1.5123456789);
	printf("1.0: %f\n", 1.0);
	printf("1.000: %f\n", 1.000);
	printf("1.0000000000: %f\n", 1.0000000000);
	//	printf("1: %f\n", 1);
	printf("1.01 %f\n", 1.01);
	printf("1.50 %f\n", 1.50);
	printf("1.5000000000: %f\n", 1.5000000000);
	printf("1.5123000000: %f\n", 1.5123000000);
	printf("015.015 %f\n", 015.015);
	//	printf("015 %f\n", 015);
	printf("015.00 %f\n", 015.00);
	printf("1234567.1234567 %f\n", 1234567.1234567);
	printf("12345678.12345678 %f\n", 12345678.12345678);
	printf("2147483647.12345678 %.8f\n", 2147483647.12345678);
	printf("2147483648.12345678 %.15Lf\n", (long double)2.1);
//	pf_ftoa(15.36, str, 2);
//	printf("|%s|\n", str);
	return (0);
}*/
