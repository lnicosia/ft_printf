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
//	printf("%d\n", len);
//	printf("avant rev_str = |%s|\n", str);
	while (i < len)
	{ 
		tmp = str[i]; 
		str[i] = str[len - 1]; 
		str[len - 1] = tmp;
		i++;
		len--; 
	} 
//	printf("apres rev_str = |%s|\n", str);
}

int		pf_itoa(t_data *data, long nb, int precision)
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
//	printf("str = |%s|\n", str);
	rev_str(str, i);
	str[++i] = '\0';
	fill_buffer(data, str, size);
	free(str);
	str = NULL;
	return (i);
}

void	pf_putfloat(t_data *data)
{
	int			i;
	long		i_part;
	double	nb;
	double		f_part;

	if (data->prec == -1)
		data->prec = 6;
	nb = va_arg(data->ap, double);
	i_part = (long)nb;
	//printf("%f\n", nb);
	f_part = nb - (double)i_part;
	i = pf_itoa(data, i_part, 0);
	if (data->prec != 0)
	{
		fill_buffer(data, ".", 1);
		f_part = f_part * power_over_nine_thousand(10, data->prec) + 0.5;
	//	printf("f_part %ld\n", (long)(f_part + 0.5));
		pf_itoa(data, (long)f_part, data->prec);
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
