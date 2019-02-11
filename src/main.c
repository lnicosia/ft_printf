/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:02:44 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/11 19:29:28 by gaerhard         ###   ########.fr       */
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
	printf("sizeof(double) = %lu\n", sizeof(double));
	printf("sizeof(long double) = %lu\n", sizeof(long double));
}

int		main(void)
{
	/*long a = 0;
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
	ft_printf("ft_printf: adrr :	%p\n", &a);
	printf("printf: adrr :		%p\n\n", &a);
	ft_printf("Long test:\naaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbb\n\n");*/
	//ft_printf("%cb%%\nnb1 = %d\nnb2 = %d\n", 'a', 5, 457);
	/*ft_printf("Test:\n");
	printf("4567 |%-10]5d| plip\n", 12);
	printf("4567 |%10]5d| plip\n", 12);
	printf("|%06d|\n", -12);
	printf("|%.5d|\n", -12);
	printf("|%10.5d|\n", -12);
	printf("|%10d|\n", -12);
	printf("|%10ld|\n", -12);
	printf("|%010d|\n", -12); 
	printf("|%-10.5d|\n", -12);
	printf("|%-010.5d|\n", -12);
	printf("|%-10.5c|\n\n", 'a');*/

	/*ft_printf("Tests erreurs options:\n");
	printf("|%00  4d|\n", 7);
	printf("|%00  4lhd|\n", -2147483649544444);
	ft_printf("|%00  4lhd|\n", -2147483649544444);
	printf("|%00  4hld|\n", -214748364944444);
	printf("|%hhd|\n", 654654654);*/
	
/*	ft_printf("Precision:\n");
	ft_printf("|%+.2d|\n", 5); printf("|%+.2d|\n\n", 5);
	ft_printf("|%.5d|\n", -500); printf("|%.5d|\n\n", -500);
	ft_printf("|%.1d|\n", -500); printf("|%.1d|\n\n", -500);
	ft_printf("|%.2d|\n", 5); printf("|%.2d|\n\n", 5);
	ft_printf("|%.2d|\n", -5); printf("|%.2d|\n\n", -5);
	ft_printf("|%.5d|\n", -5); printf("|%.5d|\n\n", -5);
	ft_printf("|%10.5d|\n", 5); printf("|%10.5d|\n\n", 5);
	ft_printf("|%010.5d|\n", 5); printf("|%010.5d|\n\n", 5);
	ft_printf("|%010d|\n", 5); printf("|%010d|\n\n", 5);
	ft_printf("|%-010d|\n", 5); printf("|%-010d|\n\n", 5);
	ft_printf("|%010.1d|\n", 5); printf("|%010.1d|\n\n", 5);
	ft_printf("|%010.0d|\n", 5); printf("|%010.1d|\n\n", 5);
	ft_printf("|%10.5d|\n", -5); printf("|%10.5d|\n\n", -5);
	ft_printf("|%-10.5d|\n", -5); printf("|%-10.5d|\n\n", -5);
	ft_printf("|% 10.5d|\n", 5); printf("|% 10.5d|\n\n", 5);
	ft_printf("|%- 10.5d|\n", 5); printf("|%- 10.5d|\n\n", 5);
	ft_printf("|%-+ 10.5d|\n", 5); printf("|%-+ 10.5d|\n\n", 5);
	ft_printf("|%+- 10.5d|\n", -5); printf("|%+- 10.5d|\n\n", -5);*/

/*	ft_printf("Check global %%d:\n");

	ft_printf("|%   ++++    ---  15.5hhd|\n", 127);
	printf("|%   ++++    ---  15.5hhd|\n", 127);
	ft_printf("|%   ++++    ---  15.5hhd|\n", 128);
	printf("|%   ++++    ---  15.5hhd|\n", 128);
	ft_printf("|% 00  ++++  00  ---  15.5hhd|\n", 127);
	printf("|% 00  ++++ 00   ---  15.5hhd|\n", 127);*/

/*	ft_printf("\nl_min:\n");
	ft_printf("|%d|", 5); printf("\n|%d|\n", 5);
	ft_printf("|%10hhd|", 127); printf("\n|%10hhd|\n", 127);
	ft_printf("|%10hhd|", 128); printf("\n|%10hhd|\n", 128);
	ft_printf("|%10hhd|", -5); printf("\n|%10hhd|\n", -5);
	ft_printf("|%3d|", 4000); printf("\n|%3d|\n", 4000);
	ft_printf("|%3d|", -4000); printf("\n|%3d|\n", -4000);
	ft_printf("|%3d|", -400); printf("\n|%3d|\n", -400);
	ft_printf("\n\'0\':\n");
	ft_printf("|%0d|", 5); printf("\n|%0d|\n", 5);
	ft_printf("|%010hhd|", 127); printf("\n|%010hhd|\n", 127);
	ft_printf("|%010hhd|", 128); printf("\n|%010hhd|\n", 128);
	ft_printf("|%010hhd|", -5); printf("\n|%010hhd|\n", -5);
	ft_printf("\n\'-\':\n");
	ft_printf("|%-0d|", 5); printf("\n|%-0d|\n", 5);
	ft_printf("|%-010hhd|", 127); printf("\n|%-010hhd|\n", 127);
	ft_printf("|%-010hhd|", 128); printf("\n|%-010hhd|\n", 128);
	ft_printf("|%-010hhd|", -5); printf("\n|%-010hhd|\n", -5);
	ft_printf("\n\'+\':\n");
	ft_printf("|%+0d|", 5); printf("\n|%+0d|\n", 5);
	ft_printf("|%+010hhd|", 127); printf("\n|%+010hhd|\n", 127);
	ft_printf("|%+010hhd|", 128); printf("\n|%+010hhd|\n", 128);
	ft_printf("|%+010hhd|", -5); printf("\n|%+010hhd|\n", -5);
	ft_printf("|%+d|", 5); printf("\n|%+d|\n", 5);
	ft_printf("|%+10hhd|", 127); printf("\n|%+10hhd|\n", 127);
	ft_printf("|%+10hhd|", 128); printf("\n|%+10hhd|\n", 128);
	ft_printf("|%+10hhd|", -5); printf("\n|%+10hhd|\n", -5);*/

	/*ft_printf("\nOptions:\n");
	ft_printf("|%+++d|", 5); printf("\n|%+++0d|\n\n", 5);
	ft_printf("|%+++10hhd|", 127); printf("\n|%+++10hhd|\n\n", 127);
	ft_printf("|%+++10hhd|", 128); printf("\n|%+++10hhd|\n\n", 128);
	ft_printf("|%+++10hhd|", -5); printf("\n|%+++10hhd|\n\n", -5);
	ft_printf("|%----+++0d|", 5); printf("\n|%----+++0d|\n\n", 5);
	ft_printf("|%----+++10hhd|", 127); printf("\n|%----+++10hhd|\n\n", 127);
	ft_printf("|%----+++10hhd|", 128); printf("\n|%----+++10hhd|\n\n", 128);
	ft_printf("|%----+++10hhd|", -5); printf("\n|%----+++10hhd|\n\n", -5);
	ft_printf("|%  0 010d|", 5); printf("\n|%  0 010d|\n\n", 5);
	ft_printf("|%  0 010d|", 127); printf("\n|%  0 010d|\n\n", 127);
	ft_printf("|%  0 010d|", 128); printf("\n|%  0 010d|\n\n", 128);
	ft_printf("|%  0 010d|", -5); printf("\n|%  0 010d|\n\n", -5);
	ft_printf("|%   10d|", -5); printf("\n|%   10d|\n\n", -5);
	ft_printf("|% ----  10d|", -5); printf("\n|% ----  10d|\n\n", -5);
	ft_printf("|% ----  010d|", -5); printf("\n|% ----  010d|\n\n", -5);
	ft_printf("|% -+-+-+-  010d|", -5); printf("\n|% -+-+-+-  010d|\n\n", -5);
	ft_printf("|% -+-+-+-  010d|", 5); printf("\n|% -+-+-+-  010d|\n\n", 5);
	ft_printf("|% ----  10d|", 5); printf("\n|% ----  10d|\n\n", 5);*/

	/*ft_printf("\n%%hhd:\n");
	ft_printf("|%hhd|", 127); printf("	|%hhd|\n", 127);
	ft_printf("|%hhd|", 128); printf("	|%hhd|\n", 128);
	ft_printf("|%hhd|", -128); printf("	|%hhd|\n", -128);
	ft_printf("|%hhd|", -129); printf("	|%hhd|\n", -129);
	
	ft_printf("\n%%hd:\n");
	ft_printf("|%hd|", 32767); printf("		|%hd|\n", 32767);
	ft_printf("|%hd|", 32768); printf("	|%hd|\n", 32768);
	ft_printf("|%hd|", -32768); printf("	|%hd|\n", -32768);
	ft_printf("|%hd|", -32769); printf("		|%hd|\n", -32769);
	
	ft_printf("\n%%d:\n");
	ft_printf("|%d|", 2147483647); printf("	|%d|\n", 2147483647);
	ft_printf("|%d|", 2147483648); printf("	|%d|\n", 2147483648);
	ft_printf("|%d|", -2147483648); printf("	|%d|\n", -2147483648);
	ft_printf("|%d|", -2147483649); printf("	|%d|\n", -2147483649);
	
	ft_printf("\n%%l:\n");
	ft_printf("|%ld|", 9223372036854775807); printf("	|%ld|\n", 9223372036854775807);
	ft_printf("|%ld|", 9223372036854775808); printf("	|%ld|\n", 9223372036854775808);
	ft_printf("|%ld|", -9223372036854775808); printf("	|%ld|\n", -9223372036854775808);
	ft_printf("|%ld|", -9223372036854775809); printf("	|%ld|\n", -9223372036854775809);
	
	ft_printf("\n%%ll:\n");
	ft_printf("|%lld|", 9223372036854775807); printf("	|%lld|\n", 9223372036854775807);
	ft_printf("|%lld|", 9223372036854775808); printf("	|%lld|\n", 9223372036854775808);
	ft_printf("|%lld|", -9223372036854775808); printf("	|%lld|\n", -9223372036854775808);
	ft_printf("|%lld|", -9223372036854775809); printf("	|%lld|\n", -9223372036854775809);*/
	//sizes();
	//
	/*ft_printf("%%c:\n");
	printf("|%010c|\n", 110);
	ft_printf("|%010c|\n\n", 110);
	printf("|%010c|\n", 110);
	ft_printf("|%010c|\n\n", 110);
	printf("|%-10c|\n", 'n');
	ft_printf("|%-10c|\n\n", 'n');
	printf("|%+10c|\n", 'n');
	ft_printf("|%+10c|\n\n", 'n');
	printf("|%- 10c|\n", 'n');
	ft_printf("|%- 10c|\n\n", 'n');
	printf("|%10.5c|\n", 110);
	ft_printf("|%10.5c|\n\n", 110);
	printf("|%10.5c|\n", 'n');
	ft_printf("|%10.5c|\n\n", 'n');
	ft_printf("|%   ++++    ---  15.5c|\n", 'a');
	printf("|%   ++++    ---  15.5c|\n", 'a');
	ft_printf("|%   ++++      15.5c|\n", 'a');
	printf("|%   ++++      15.5c|\n", 'a');
	ft_printf("|% 00  ++++  00  ---  15.5c|\n", 'a');
	printf("|% 00  ++++ 00   ---  15.5c|\n", 'a');
	ft_printf("|% 00  ++++  00  ---  15.5d|\n", 'a');
	printf("|% 00  ++++ 00   ---  15.5d|\n", 'a');*/
	
	/*ft_printf("%%s:\n");
	printf("|%010s|\n", "bonjour");
	ft_printf("|%010s|\n\n", "bonjour");
	printf("|%010s|\n", "ab");
	ft_printf("|%010s|\n\n", "ab");
	printf("|%-10s|\n", "nb");
	ft_printf("|%-10s|\n\n", "nb");
	printf("|%+10s|\n", "nb");
	ft_printf("|%+10s|\n\n", "nb");
	printf("|%- 10s|\n", "nb");
	ft_printf("|%- 10s|\n\n", "nb");
	printf("|%10.5s|\n", "012345dbwvvvfdfsf01234");
	ft_printf("|%10.5s|\n\n", "012345fsdfdfsfds01234");
	printf("|%010.5s|\n", "nb");
	ft_printf("|%010.5s|\n\n", "nb");
	ft_printf("|%   ++++    ---  15.5s|\n", "ab");
	printf("|%   ++++    ---  15.5s|\n", "ab");
	ft_printf("|%   ++++      15.5s|\n", "des mots");
	printf("|%   ++++      15.5s|\n", "des mots");
	ft_printf("|% 00  ++++  00  ---  15.5s|\n", "demo");
	printf("|% 00  ++++ 00   ---  15.5s|\n", "demo");
	ft_printf("|% 00  ++++  00  ---  15.5d|\n", "a");
	printf("|% 00  ++++ 00   ---  15.5d|\n", "a");*/
	return (0);
}
