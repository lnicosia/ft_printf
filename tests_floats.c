#include <stdio.h>
int		power_over_nine_thousand(int nb, int power)
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
int		pf_itoa(int nb, char *str, int precision)
{
	int i;

	i = 0;
	while (nb)
	{
		str[i++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	while (i < precision)
		str[i++] = '0';
	//printf("inside itoa|%s|\n", str);
	rev_str(str, i);
	str[i] = '\0';
	return (i);
}

void	pf_ftoa(double nb, char *res, int precision)
{
	int		i;
	int		i_part;
	double	f_part;

	i_part = (int)nb;
	f_part = nb - (float)i_part;
	i = pf_itoa(i_part, res, 0);
	if (precision != 0)
	{
		res[i] = '.';
		f_part = f_part * power_over_nine_thousand(10, precision);
		printf("f_part %d\n", (int)(f_part + 0.5));
		pf_itoa((int)f_part, res + i + 1, precision);
	}
}

int	main(void)
{
	char *str;

	printf("15.36: %.2f\n", 15.36);
	printf("1.5123: %f\n", 1.5123);
	printf("1.5123456789: %f\n", 1.5123456789);
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
	pf_ftoa(15.36, str, 2);
	printf("|%s|\n", str);
	return (0);
}
