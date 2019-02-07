/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:02:44 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/07 17:32:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	long a = 0;
	ft_printf("J'ai %i %s et %c yeux et 0.1%% de capacite cerebrale\n\n", 4, "dents", '2');
	printf("J'ai %i %s et %c yeux et 0.1%% de capacite cerebrale\n\n", 4, "dents", '2');
	ft_printf("ft_printf: uint:	%u\n", 55555);
	printf("printf: uint:		%u\n\n", 55555);
	ft_printf("ft_printf: hexa:	%x\n", 55555);
	printf("printf: hexa:		%x\n\n", 55555);
	ft_printf("ft_printf: hexa maj:	%X\n", 55555);
	printf("printf: hexa maj:	%X\n\n", 55555);
	ft_printf("ft_printf: octal:	%o\n", 55555);
	printf("printf: otcal:		%o\n\n", 55555);
	ft_printf("ft_printf: adrr &int:	%p\n", &a);
	printf("printf: adrr &int:	%p\n\n", &a);
	ft_printf("Coucou\n%c", 4);
	//ft_printf("%cb%%\nnb1 = %d\nnb2 = %d\n", 'a', 5, 457);
	return (0);
}
