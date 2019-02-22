/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:02:44 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/22 16:19:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include "color.h"

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
	ft_printf("|{red}rouge {green}vert {yellow}jaune {cyan}cyan {magenta}magenta {blue}bleu{reset}|\n");
	ft_printf("|{{red}rouge {green}vert {{{{yellow}jaune {cyan}cyan {{magenta}magenta {blue}bleu{reset}|\n");
	ft_printf(" {{ {querty} {\n");
	printf("{red}rouge {green}vert {yellow}jaune {reset}\n");
	/*int ret = printf(RESET); printf("red = %d\n", ret);
	printf(RESET);*/

	int ret = ft_printf("invalid%");
	printf("ret = %d\n", ret);
	ret = printf("invalid%");
	printf("ret = %d\n\n", ret);
	/*ft_printf("{% S}\n", "(null)");
	printf("{% S}\n\n", "(null)");

	ft_printf("|%s|\n", "abc");
	printf("|%s|\n\n", "abc");

	ft_printf("|%4.s|\n", "42");
	printf("|%4.s|\n\n", "42");

	ft_printf("|%4.1s|\n", "42");
	printf("|%4.1s|\n\n", "42");

	ft_printf("|%4s|\n", "42");
	printf("|%4s|\n\n", "42");

	ft_printf("|%.01s|\n", "");
	printf("|%.01s|\n\n", "");

	ft_printf("|%.02s|\n", "");
	printf("|%.02s|\n\n", "");

	ft_printf("|%2s|\n", "");
	printf("|%2s|\n\n", "");*/

	/*ft_printf("|%01.u|\n", 0);
	printf("|%01.u|\n\n", 0);

	ft_printf("|%01.d|\n", 0);
	printf("|%01.d|\n\n", 0);*/

	//ft_printf("|%d||%d||%d|\n");

	/*ft_printf(NULL);
	ft_printf(NULL, 123, 'A', 1235.123);*/

	/*ft_printf("|%f|\n", -12547.58);
	printf("|%f|\n\n", -12547.58);*/

	/*ft_printf(">------------<%1.14s>------------<\n", "");
	printf(">------------<%1.14s>------------<\n\n", "");
	
	ft_printf("test %-10.2ls!!\n", L"〻");
	printf("test %-10.2ls!!\n", L"〻");

	ft_printf("|u{%4.2s}s {%-1.s} {%---5.3s}|\n", "coco", NULL, "yooo");
	printf("|u{%4.2s}s {%-1.s} {%---5.3s}|\n\n", "coco", NULL, "yooo");

	ft_printf("|%-1.1s|\n", NULL);
	printf("|%-1.1s|\n\n", NULL);

	ft_printf("|%-1.s|\n", NULL);
	printf("|%-1.s|\n\n", NULL);

	ft_printf("|%-2.s|\n", NULL);
	printf("|%-2.s|\n\n", NULL);

	ft_printf("|%10s|\n", NULL);
	printf("|%10s|\n\n", NULL);

	ft_printf("|%010s|\n", NULL);
	printf("|%010s|\n\n", NULL);

	ft_printf("|%0.s|\n", "hi");
	printf("|%0.s|\n\n", "hi");

	ft_printf("|%---12s|\n", 0);
	printf("|%---12s|\n\n", 0);*/

	/*ft_printf("|%d|\n", 0.123);
	printf("|%d|\n", 0.123);*/

	/*ft_printf("|%d|\n", 5, 5);
	printf("|%d|\n\n", 5, 5);

	ft_printf("|%d%d|\n", 5);
	printf("|%d%d|\n\n", 5);*/


	/*ft_printf("{%#5b}\n", 1);
	printf("{%#5x}\n\n", 1);

	ft_printf("{%#5b}\n", 0);
	printf("{%#5x}\n\n", 0);

	ft_printf("{%5b}\n", 0);
	printf("{%5x}\n\n", 0);

	ft_printf("{%#.b, %#.0b}\n", 0, 0);
	printf("{%#.x, %#.0x}\n\n", 0, 0);

	ft_printf("{%.b, %.0b}\n", 0, 0);
	printf("{%.x, %.0x}\n\n", 0, 0);

	ft_printf("{%#.b, %#.0b}\n", 1, 1);
	printf("{%#.x, %#.0x}\n\n", 1, 1);

	ft_printf("{%.b, %.0b}\n", 1, 1);
	printf("{%.x, %.0x}\n\n", 1, 1);

	ft_printf("{%#05b, %#05b}\n", 1, 1);
	printf("{%#05x, %#05x}\n\n", 1, 1);

	ft_printf("|%#7.5b|\n", 0xab);
	printf("|%#7.5x|\n\n", 0xab);

	ft_printf("|%7.5b|\n", 0xab);
	printf("|%7.5x|\n\n", 0xab);

	ft_printf("{%#.5b}\n", 1);
	printf("{%#.5x}\n\n", 1);

	ft_printf("{%.5b}\n", 1);
	printf("{%.5x}\n\n", 1);

	ft_printf("{%#.5b}\n", 0);
	printf("{%#.5x}\n\n", 0);

	ft_printf("{%.b}\n", 0);
	printf("{%.x}\n\n", 0);

	ft_printf("{%5.b}\n", 0);
	printf("{%5.x}\n\n", 0);

	ft_printf("{%.5b}\n", 0);
	printf("{%.5x}\n\n", 0);

	ft_printf("{%5.5b}\n", 0);
	printf("{%5.5x}\n\n", 0);*/

	/*ft_printf("{%#5o}\n", 1);
	printf("{%#5o}\n\n", 1);

	ft_printf("{%#5o}\n", 0);
	printf("{%#5o}\n\n", 0);

	ft_printf("{%5o}\n", 0);
	printf("{%5o}\n\n", 0);

	ft_printf("{%#.o, %#.0o}\n", 0, 0);
	printf("{%#.o, %#.0o}\n\n", 0, 0);

	ft_printf("{%.o, %.0o}\n", 0, 0);
	printf("{%.o, %.0o}\n\n", 0, 0);

	ft_printf("{%#.o, %#.0o}\n", 1, 1);
	printf("{%#.o, %#.0o}\n\n", 1, 1);

	ft_printf("{%.o, %.0o}\n", 1, 1);
	printf("{%.o, %.0o}\n\n", 1, 1);

	ft_printf("{%#05o, %#05o}\n", 1, 1);
	printf("{%#05o, %#05o}\n\n", 1, 1);

	ft_printf("|%#7.5o|\n", 0xab);
	printf("|%#7.5o|\n\n", 0xab);

	ft_printf("|%7.5o|\n", 0xab);
	printf("|%7.5o|\n\n", 0xab);

	ft_printf("|%#7.5o|\n", 0xab);
	printf("|%#7.5o|\n\n", 0xab);

	ft_printf("{%#.5o}\n", 1);
	printf("{%#.5o}\n\n", 1);

	ft_printf("{%.5o}\n", 1);
	printf("{%.5o}\n\n", 1);

	ft_printf("{%5.5o}\n", 1);
	printf("{%5.5o}\n\n", 1);

	ft_printf("{%#.5o}\n", 0);
	printf("{%#.5o}\n\n", 0);

	ft_printf("{%.o}\n", 0);
	printf("{%.o}\n\n", 0);

	ft_printf("{%5.o}\n", 0);
	printf("{%5.o}\n\n", 0);

	ft_printf("{%.5o}\n", 0);
	printf("{%.5o}\n\n", 0);

	ft_printf("{%5.5o}\n", 0);
	printf("{%5.5o}\n\n", 0);*/

	/*ft_printf("{%05.%}\n", 0);
	printf("{%05.%}\n\n", 0);

	ft_printf("{%5.%}\n", 0);
	printf("{%5.%}\n\n", 0);

	ft_printf("{%05.1%}\n", 0);
	printf("{%05.1%}\n\n", 0);
	
	ft_printf("{%05.3%}\n", 0);
	printf("{%05.3%}\n\n", 0);*/

	/*ft_printf("{%5p}\n", 0);
	printf("{%5p}\n\n", 0);

	ft_printf("|%9.2p|\n", 1234);
	printf("|%9.2p|\n\n", 1234);

	ft_printf("|%9.2p|\n", 0);
	printf("|%9.2p|\n\n", 0);

	ft_printf("|%9.p|\n", 1234);
	printf("|%9.p|\n\n", 1234);

	ft_printf("|%9.0p|\n", 0);
	printf("|%9.0p|\n\n", 0);*/

	/*ft_printf("@moulitest: |%.o %.0o|\n", 0, 0);
	printf("@moulitest: |%.o %.0o|\n\n", 0, 0);

	ft_printf("@moulitest: |%#.o %#.0o|\n", 0, 0);
	printf("@moulitest: |%#.o %#.0o|\n\n", 0, 0);

	ft_printf("@moulitest: |%o|\n", 0);
	printf("@moulitest: |%o|\n\n", 0);

	ft_printf("|%#o|\n", 0);
	printf("|%#o|\n\n", 0);

	ft_printf("|%#.o|\n", 0);
	printf("|%#.o|\n\n", 0);

	ft_printf("|%#6o|\n", 2500);
	printf("|%#6o|\n\n", 2500);

	ft_printf("|%-#6o|\n", 2500);
	printf("|%-#6o|\n\n", 2500);*/
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

	/*ft_printf("Check global %%d:\n");

	ft_printf("|%       ---  15.5hhu|\n", 127);
	printf("|%       ---  15.5hhu|\n\n", 127);
	ft_printf("|%       ---  15.5hhu|\n", 128);
	printf("|%       ---  15.5hhu|\n\n", 128);
	ft_printf("|% 00    00    15.5hhu|\n", 127);
	printf("|% 00   00     15.5hhu|\n\n", 127);
	ft_printf("|% 00    00    15.0hhu|\n", 127);
	printf("|% 00   00     15.0hhu|\n\n", 127);
	ft_printf("|% 00    00    15.0hhu|\n", 127);
	printf("|% 00   00     15.0hhu|\n\n", 127);*/

	/*ft_printf("\nCheck global %%x:\n\n");

	ft_printf("|%       ---  15.5hhx|\n", 255);
	printf("|%       ---  15.5hhx|\n\n", 255);
	ft_printf("|%       ---  15.5hhx|\n", 256);
	printf("|%       ---  15.5hhx|\n\n", 256);
	ft_printf("|%       ---  15.5hhx|\n", 0);
	printf("|%       ---  15.5hhx|\n\n", 0);
	ft_printf("|% 00    00    15.5x|\n", 127);
	printf("|% 00   00     15.5x|\n\n", 127);
	ft_printf("|% 00    00    15.0x|\n", 127);
	printf("|% 00   00     15.0x|\n\n", 127);
	ft_printf("|% 00    00    15.0x|\n", 127);
	printf("|% 00   00     15.0x|\n\n", 127);
	ft_printf("|% 00   --- 00    15.0x|\n", 127);
	printf("|% 00   ---00     15.0x|\n\n", 127);
	ft_printf("|% 00   --- 00 ++   15.0x|\n", 127);
	printf("|% 00   ---00   +++  15.0x|\n\n", 127);
	ft_printf("|%++   15.0x|\n", 127);
	printf("|%++  15.0x|\n", 127);

	ft_printf("\nCheck global %%X:\n\n");

	ft_printf("|%       ---  15.5hhX|\n", 255);
	printf("|%       ---  15.5hhX|\n\n", 255);
	ft_printf("|%       ---  15.5hhX|\n", 256);
	printf("|%       ---  15.5hhX|\n\n", 256);
	ft_printf("|%       ---  15.5hhX|\n", 0);
	printf("|%       ---  15.5hhX|\n\n", 0);
	ft_printf("|% 00    00    15.5X|\n", 127);
	printf("|% 00   00     15.5X|\n\n", 127);
	ft_printf("|% 00    00    15.0X|\n", 127);
	printf("|% 00   00     15.0X|\n\n", 127);
	ft_printf("|% 00    00    15.0X|\n", 127);
	printf("|% 00   00     15.0X|\n\n", 127);
	ft_printf("|% 00   --- 00    15.0X|\n", 127);
	printf("|% 00   ---00     15.0X|\n\n", 127);
	ft_printf("|% 00   --- 00 ++   15.0X|\n", 127);
	printf("|% 00   ---00   +++  15.0X|\n\n", 127);
	ft_printf("|%++   15.0X|\n", 127);
	printf("|%++  15.0X|\n", 127);

	ft_printf("\nCheck global %%o:\n\n");

	ft_printf("|%       ---  15.5hho|\n", 255);
	printf("|%       ---  15.5hho|\n\n", 255);
	ft_printf("|%       ---  15.5hho|\n", 256);
	printf("|%       ---  15.5hho|\n\n", 256);
	ft_printf("|%       ---  15.5hho|\n", 0);
	printf("|%       ---  15.5hho|\n\n", 0);
	ft_printf("|% 00    00    15.5o|\n", 127);
	printf("|% 00   00     15.5o|\n\n", 127);
	ft_printf("|% 00    00    15.0o|\n", 127);
	printf("|% 00   00     15.0o|\n\n", 127);
	ft_printf("|% 00    00    15.0o|\n", 127);
	printf("|% 00   00     15.0o|\n\n", 127);
	ft_printf("|% 00   --- 00    15.0o|\n", 127);
	printf("|% 00   ---00     15.0o|\n\n", 127);
	ft_printf("|% 00   --- 00 ++   15.0o|\n", 127);
	printf("|% 00   ---00   +++  15.0o|\n\n", 127);
	ft_printf("|%++   15.0o|\n", 127);
	printf("|%++  15.0o|\n", 127);*/

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
