/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   fy: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:02:44 fy lnicosia          #+#    #+#             */
/*   Updated: 2019/02/18 17:23:48 by lnicosia         ###   ########.fr       */
/*   Updated: 2019/02/13 18:11:31 fy lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	sizes(void)
{
	printf("sizeof(char) = %lu\n", sizeof(char));
	printf("sizeof(short) = %lu\n", sizeof(short));
	printf("sizeof(int) = %lu\n", sizeof(int));
	printf("sizeof(long) = %lu\n", sizeof(long));
	printf("sizeof(long long) = %lu\n", sizeof(long long));
	printf("sizeof(float) = %lu\n", sizeof(float));
	printf("sizeof(doufle) = %lu\n", sizeof(double));
	printf("sizeof(long doufle) = %lu\n", sizeof(long double));
}

int		main(void)
{
	double		nb;

	nb = 1.0/0.0;
	ft_printf("|%f|\n", nb);
	printf("|%f|\n\n", nb);
	ft_printf("|%12f|\n", nb);
	printf("|%12f|\n\n", nb);
	ft_printf("|%-12f|\n", nb);
	printf("|%-12f|\n\n", nb);
	ft_printf("|%5.f|\n", nb);
	printf("|%5.f|\n\n", nb);

	nb = 1.0/0.0;
	ft_printf("|% f|\n", nb);
	printf("|% f|\n\n", nb);
	ft_printf("|% 12f|\n", nb);
	printf("|% 12f|\n\n", nb);
	ft_printf("|%- 12f|\n", nb);
	printf("|%- 12f|\n\n", nb);
	ft_printf("|% 5.9f|\n", nb);
	printf("|% 5.9f|\n\n", nb);

	nb = -1.0/0.0;
	ft_printf("|%f|\n", nb);
	printf("|%f|\n\n", nb);
	ft_printf("|%12f|\n", nb);
	printf("|%12f|\n\n", nb);
	ft_printf("|%-12f|\n", nb);
	printf("|%-12f|\n\n", nb);
	ft_printf("|%5.9f|\n", nb);
	printf("|%5.9f|\n\n", nb);

	nb = 0.0/0.0;
	ft_printf("|%f|\n", nb);
	printf("|%f|\n\n", nb);
	ft_printf("|%12f|\n", nb);
	printf("|%12f|\n\n", nb);
	ft_printf("|%-12f|\n", nb);
	printf("|%-12f|\n\n", nb);
	ft_printf("|%5.9f|\n", nb);
	printf("|%5.9f|\n\n", nb);
	/*double		nb;
	  nb = -0.0;
	  ft_printf("|% f|\n", nb);
	  printf("|% f|\n", nb);
	  ft_printf("|%+f|\n", nb);
	  printf("|%+f|\n", nb);
	  ft_printf("|%#f|\n", nb);
	  printf("|%#f|\n", nb);
	  ft_printf("|%.2f|\n", nb);
	  printf("|%.2f|\n", nb);
	  ft_printf("|%.14f|\n", nb);
	  printf("|%.14f|\n", nb);
	  ft_printf("|%#.0f|\n", nb);
	  printf("|%#.0f|\n", nb);
	  ft_printf("|% .5f|\n", nb);
	  printf("|% .5f|\n", nb);
	  ft_printf("|%# .0f|\n", nb);
	  printf("|%# .0f|\n", nb);
	  ft_printf("|% #.0f|\n", nb);
	  printf("|% #.0f|\n", nb);
	  ft_printf("|%+.5f|\n", nb);
	  printf("|%+.5f|\n", nb);
	  ft_printf("|%+.0f|\n", nb);
	  printf("|%+.0f|\n", nb);
	  ft_printf("|%#+.0f|\n", nb);
	  printf("|%#+.0f|\n", nb);
	  ft_printf("|%0.5f|\n", nb);
	  printf("|%0.5f|\n", nb);
	  ft_printf("|%-.5f|\n", nb);
	  printf("|%-.5f|\n", nb);
	  ft_printf("|%5f|\n", nb);
	  printf("|%5f|\n", nb);
	  ft_printf("|% 5f|\n", nb);
	  printf("|% 5f|\n", nb);
	  ft_printf("|%+5f|\n", nb);
	  printf("|%+5f|\n", nb);
	  ft_printf("|%# 5f|\n", nb);
	  printf("|%# 5f|\n", nb);
	  ft_printf("|%#+5f|\n", nb);
	  printf("|%#+5f|\n", nb);
	  ft_printf("|%-5f|\n", nb);
	  printf("|%-5f|\n", nb);
	  ft_printf("|%05f|\n", nb);
	  printf("|%05f|\n", nb);
	  ft_printf("|%+05f|\n", nb);
	  printf("|%+05f|\n", nb);
	  ft_printf("|%0+5f|\n", nb);
	  printf("|%0+5f|\n", nb);
	  ft_printf("|%05.3f|\n", nb);
	  printf("|%05.3f|\n", nb);
	  ft_printf("|%0#5.0f|\n", nb);
	  printf("|%0#5.0f|\n", nb);
	  ft_printf("|%-5.3f|\n", nb);
	  printf("|%-5.3f|\n", nb);
	  ft_printf("|%-#5.0f|\n", nb);
	  printf("|%-#5.0f|\n", nb);
	  ft_printf("|%+05.3f|\n", nb);
	  printf("|%+05.3f|\n", nb);
	  ft_printf("|%0+#5.0f|\n", nb);
	  printf("|%0+#5.0f|\n", nb);
	  ft_printf("|%0 5.3f|\n", nb);
	  printf("|%0 5.3f|\n", nb);
	  ft_printf("|% 05.3f|\n", nb);
	  printf("|% 05.3f|\n", nb);
	  ft_printf("|%#0 5.0f|\n", nb);
	  printf("|%#0 5.0f|\n", nb);
	  ft_printf("|%-+5.3f|\n", nb);
	  printf("|%-+5.3f|\n", nb);
	  ft_printf("|%-#+5.0f|\n", nb);
	  printf("|%-#+5.0f|\n", nb);*/

	/*ft_printf("{% 5.f}\n", 137.0);
	  printf("{% 5.f}\n\n", 137.0);

	  ft_printf("{%05.f}\n", 137.0);
	  printf("{%05.f}\n\n", 137.0);

	  ft_printf("{%-05.f}\n", 137.0);
	  printf("{%-05.f}\n\n", 137.0);

	  ft_printf("{%+5.f}\n", 137.0);
	  printf("{%+5.f}\n\n", 137.0);

	  ft_printf("{%+#5.f}\n", 137.0);
	  printf("{%+#5.f}\n\n", 137.0);

	  ft_printf("{%-5.f}\n", 137.0);
	  printf("{%-5.f}\n\n", 137.0);

	  ft_printf("{%#5.f}\n", 137.0);
	  printf("{%#5.f}\n\n", 137.0);

	  ft_printf("{%5.f}\n", 137.0);
	  printf("{%5.f}\n\n", 137.0);

	  ft_printf("{%5.f}\n", 0.0);
	  printf("{%5.f}\n\n", 0.0);

	  ft_printf("{%#5f}\n", 1.0);
	  printf("{%#5f}\n\n", 1.0);

	  ft_printf("{%#5f}\n", 0.0);
	  printf("{%#5f}\n\n", 0.0);

	  ft_printf("{%5f}\n", 0.0);
	  printf("{%5f}\n\n", 0.0);*/
	/*ft_printf("{%#.f, %#.0f}\n", 0.0, 0.0);
	  printf("{%#.f, %#.0f}\n\n", 0.0, 0.0);

	  ft_printf("{%.f, %.0f}\n", 0.0, 0.0);
	  printf("{%.f, %.0f}\n\n", 0.0, 0.0);

	  ft_printf("{%#.f, %#.0f}\n", 1.0, 1.0);
	  printf("{%#.f, %#.0f}\n\n", 1.0, 1.0);

	  ft_printf("{%.f, %.0f}\n", 1.0, 1.0);
	  printf("{%.f, %.0f}\n\n", 1.0, 1.0);

	  ft_printf("{%#05f, %#05f}\n", 1.0, 1.0);
	  printf("{%#05f, %#05f}\n\n", 1.0, 1.0);

	  ft_printf("|%#07.5f|\n", 175.0);
	  printf("|%#07.5f|\n\n", 175.0);

	  ft_printf("|%7.5f|\n", 175.0);
	  printf("|%7.5f|\n\n", 175.0);

	  ft_printf("{%#.5f}\n", 1.0);
	  printf("{%#.5f}\n\n", 1.0);

	  ft_printf("{%.5f}\n", 1.0);
	  printf("{%.5f}\n\n", 1.0);

	  ft_printf("{%#.5f}\n", 0.0);
	  printf("{%#.5f}\n\n", 0.0);

	  ft_printf("{%.f}\n", 0.0);
	  printf("{%.f}\n\n", 0.0);

	  ft_printf("{%5f}\n", 1.5);
	  printf("{%5f}\n\n", 1.5);

	  ft_printf("{%.5f}\n", 1.5);
	  printf("{%.5f}\n\n", 1.5);

	  ft_printf("{%5f}\n", 1500.5);
	  printf("{%5f}\n\n", 1500.5);

	  ft_printf("{%.5f}\n", 1500.5);
	  printf("{%.5f}\n\n", 1500.5);

	  ft_printf("{%5.5f}\n", 0.0);
	  printf("{%5.5f}\n\n", 0.0);*/

	/*ft_printf("2147483648.123450012: %.0f\n", 2147483648.123450012);
	  printf("2147483648.123450012: %.0f\n\n", 2147483648.123450012);
	  ft_printf("0.01: %.15f\n", 0.01);
	  printf("0.01: %.15f\n\n", 0.01);
	  ft_printf("0.0: %f\n", 0.0);
	  printf("0.0: %f\n\n", 0.0);
	//	ft_printf("1: %f\n", 1);
	//	printf("1: %f\n\n", 1);
	ft_printf("1.0: %f\n", 1.0);
	printf("1.0: %f\n\n", 1.0);
	ft_printf("01.01: %.4f\n", 01.01);
	printf("01.01: %.4f\n\n", 01.01);
	//	ft_printf("9999999999999999999: %f\n", 9999999999999999999);
	//	printf("9999999999999999999: %f\n\n", 9999999999999999999);
	ft_printf("0.00000000000000000001: %f\n", 0.00000000000000000001);
	printf("0.00000000000000000001: %f\n\n", 0.00000000000000000001);
	ft_printf("0.1234567: %f\n", 0.1234567);
	printf("0.1234567: %f\n\n", 0.1234567);
	ft_printf("0.1234564: %f\n", 0.1234564);
	printf("0.1234564: %f\n\n", 0.1234564);
	//	ft_printf("10: %f\n", 10);
	//	printf("10: %f\n\n", 10);
	//	ft_printf("-0: %f\n", -0);
	//	printf("-0: %f\n\n", -0);
	ft_printf("-1.5: %.2f\n", -1.5);
	printf("-1.5: %.2f\n\n", -1.5);
	ft_printf("-0.05: %f\n", -0.05);
	printf("-0.05: %f\n\n", -0.05);
	//	ft_printf("45: %f\n", -45);
	//	printf("45: %f\n\n", -45);*/
	return (0);
}
