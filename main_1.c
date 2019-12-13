/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:36:40 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/12/11 10:21:50 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			main()
{

	char a[5] = "aaaa\0";
	char b[5] = "bbbb\0";
	char c = '\0';
	float flt = -10.1234;
	float flt2 = 31999836477.123456789;
	float flt4 = -0.0003;
	float flt5 = 0.0;
	long long longi = -214748888888878;
	int var;



	printf(BGREEN);
	printf("MULTIPLE ARGS:\n");
	printf(BRED);
	printf("gg%c%daa%s\n", 'h', 11, b);
	ft_printf(BBLUE);
	ft_printf("gg%c%daa%s\n", 'h', 11, b);

	printf(BGREEN);
	printf("EMPTY STRING:\n");
	printf(BRED);
	printf("");
	ft_printf("");
	ft_printf("\n\n");

	printf(BGREEN);
	printf("CHAR:\n");
	printf(BRED);
	var = printf("%2c null char spa%cce and c=%c\n", c, ' ', 'c');
	ft_putnbr(var);
	ft_putendl(" returned");
	ft_printf(BBLUE);
	var = ft_printf("%2c null char spa%cce and c=%c\n", c, ' ', 'c');
	ft_putnbr(var);
	ft_putendl(" returned\n");

	printf(BGREEN);
	printf("STRING:\n");
	printf(BRED);
	var = printf("%.09s was string and %s<null\n", a, NULL);
	ft_putnbr(var);
	ft_putendl(" returned");
	ft_printf(BBLUE);
	var = ft_printf("%.009s was string and %s<null\n", a, NULL);
	ft_putnbr(var);
	ft_putendl(" returned\n");

	printf(BGREEN);
	printf("STRING precision 0 width 3:\n");
	printf(BRED);
	var = printf("%3.swas string\n", "abcd");
	ft_putnbr(var);
	ft_putendl(" returned");
	ft_printf(BBLUE);
	var = ft_printf("%3.swas string\n", "abcd");
	ft_putnbr(var);
	ft_putendl(" returned\n");

	printf(BGREEN);
	printf("STRING width 1 nullchar:\n");
	printf(BRED);
	var = printf("%1swas string\n", "\0");
	ft_putnbr(var);
	ft_putendl(" returned");
	ft_printf(BBLUE);
	var = ft_printf("%1swas string\n", "\0");
	ft_putnbr(var);
	ft_putendl(" returned\n");


	printf(BGREEN);
	printf("POINTER:\n");
	printf(BRED);
	printf("%16p\n", &longi);
	ft_printf(BBLUE);
	ft_printf("%16p\n\n", &longi);

	printf(BGREEN);
	printf("DIGIT:\n");
	printf(BRED);
	printf("%ld and %d and %d and %.09d and %09.7d\n", 2147483648, -2147483647, 0, 123, -12345);
	ft_printf(BBLUE);
	ft_printf("%ld and %d and %d and %.09d and %09.7d\n\n", 2147483648, -2147483647, 0, 123, -12345);

	printf(BGREEN);
	printf("INTEGER:\n");
	printf(BRED);
	printf("%i and %i and %i and %+i and %+i\n", 2147483647, -2147483647, 0, 12345, -12345);
	ft_printf(BBLUE);
	ft_printf("%i and %i and %i and %+i and %+i\n\n", 2147483647, -2147483647, 0, 12345, -12345);

	printf(BGREEN);
	printf("INTEGER width 05 is negative and plus:\n");
	printf(BRED);
	var = printf("%05i and %0+5i and %07i\n", -12, 12, -54);
	ft_putnbr(var);
	ft_putendl(" returned");
	ft_printf(BBLUE);
	var = ft_printf("%05i and %0+5i and %07i\n", -12, 12, -54);
	ft_putnbr(var);
	ft_putendl(" returned\n");

	printf(BGREEN);
	printf("INTEGER with empty spaces\n");
	printf(BRED);
	var = printf("%  i and %   03i and % i and this % i and % 2i and % 3i\n", 12, 12, 17, -267, 66, 66);
	ft_putnbr(var);
	ft_putendl(" returned");
	ft_printf(BBLUE);
	var = ft_printf("%  i and %   03i and % i and this % i and % 2i and % 3i\n", 12, 12, 17, -267, 66, 66);
	ft_putnbr(var);
	ft_putendl(" returned\n");

	printf(BGREEN);
	printf("INTEGER with 0 or precision 0\n");
	printf(BRED);
	var = printf("%.i and %.i and %.3i and %.3i\n", 12, 0, 12, 0);
	ft_putnbr(var);
	ft_putendl(" returned");
	ft_printf(BBLUE);
	var = ft_printf("%.i and %.i and %.3i and %.3i\n", 12, 0, 12, 0);
	ft_putnbr(var);
	ft_putendl(" returned\n");

	printf(BGREEN);
	printf("INTEGER with precision width and 0 flags (should be 00066 and 9 returned)\n");
	ft_printf(BBLUE);
	var = ft_printf("%0-8.5i\n", 66);
	ft_putnbr(var);
	ft_putendl(" returned\n");

	printf(BGREEN);
	printf("INTEGER specials\n");
	printf(BRED);
	var = printf("% 05i | % 03i | %+.0i | %+5.0i | %07i | %+8.5i\n", 12, 0, 0, 0, -66, 0);
	ft_putnbr(var);
	ft_putendl(" returned");
	ft_printf(BBLUE);
	var = ft_printf("% 05i | % 03i | %+.0i | %+5.0i | %07i | %+8.5i\n", 12, 0, 0, 0, -66, 0);
	ft_putnbr(var);
	ft_putendl(" returned\n");

	printf(BGREEN);
	printf("OCTAL:\n");
	printf(BRED);
	printf("%03o | %#o | %20o | %o | %o | %#7o | %#3o | %#-8.5o\n", 0, 12345, -12345, 2147483647, -2147483647, 33, 33, 0);
	ft_printf(BBLUE);
	ft_printf("%03o | %#o | %20o | %o | %o | %#7o | %#3o | %#-8.5o\n\n", 0, 12345, -12345, 2147483647, -2147483647, 33, 33, 0);

	printf(BGREEN);
	printf("UNSIGNED:\n");
	printf(BRED);
	printf("%u and %u and %20u and %u and %u\n", 0, 12345, -12345, 2147483647, -2147483647);
	ft_printf(BBLUE);
	ft_printf("%u and %u and %20u and %u and %u\n\n", 0, 12345, -12345, 2147483647, -2147483647);

	printf(BGREEN);
	printf("HEXADECIMAL LC:\n");
	printf(BRED);
	printf("%x and %06x and %20x and %#x and %x and %#.5x and %#x and %#05x\n", 0, 12345, -12345, 2147483647, -2147483647, 22, 0, 66);
	ft_printf(BBLUE);
	ft_printf("%x and %06x and %20x and %#x and %x and %#.5x and %#x and %#05x\n", 0, 12345, -12345, 2147483647, -2147483647, 22, 0, 66);

	printf(BGREEN);
	printf("HEXADECIMAL UC:\n");
	printf(BRED);
	printf("%X and %X and %20X and %#X and %X\n", 0, 12345, -12345, 2147483647, -2147483647);
	ft_printf(BBLUE);
	ft_printf("%X and %X and %20X and %#X and %X\n\n", 0, 12345, -12345, 2147483647, -2147483647);

	printf(BGREEN);
	printf("FLOAT:\n");
	printf(BRED);
	printf("%05.0f | % 5.0f | % 5.1f | % 5.3f | %.3f and %#f and %.19f and %f and %+f\n", 6.6, 6.6, 6.6, 6.6, flt, flt2, 123.123456789666666666, flt4, flt5);
	ft_printf(BBLUE);
	ft_printf("%05.0f | % 5.0f | % 5.1f | % 5.3f | %.3f and %#f and %.19f and %f and %+f\n\n", 6.6, 6.6, 6.6, 6.6, flt, flt2, 123.123456789666666666, flt4, flt5);

	printf(BGREEN);
	printf("MORE FLOAT:\n");
	printf(BRED);
	printf("% -5.0f | % 05.0f | % 5.3f | % 5.6f | %.1f | %#.0f | %.0f | %.0f | %.0f | %.0f | %.0f | %.12f and %.0f\n", 6.6, 6.6, -6.6, 6.6, 1.0, 1.0, -1.001, 1.01, 1.50, 1.99, 3.0, 0.999999999999999900, 0.005);
	ft_printf(BBLUE);
	ft_printf("% -5.0f | % 05.0f | % 5.3f | % 5.6f | %.1f | %#.0f | %.0f | %.0f | %.0f | %.0f | %.0f | %.12f and %.0f\n\n", 6.6, 6.6, -6.6, 6.6, 1.0, 1.0, -1.001, 1.01, 1.50, 1.99, 3.0, 0.999999999999999900, 0.005);

	printf(BGREEN);
	printf("MORE FLOAT:\n");
	printf(BRED);
	printf("%f\n", 3.9999999);
	ft_printf(BBLUE);
	ft_printf("%f\n\n", 3.9999999);

	printf(BGREEN);
	printf("MORE FLOAT:\n");
	printf(BRED);
	printf("%.15f\n", 0.87650894255);
	ft_printf(BBLUE);
	ft_printf("%.15f\n\n", 0.87650894255);

	printf(BGREEN);
	printf("PERCENT SIGN:\n");
	printf(BRED);
	printf("sign %5% in the middle and %s in the end and %-05%\n", "->string<-");
	ft_printf(BBLUE);
	ft_printf("sign %5% in the middle and %s in the end and %-05%\n\n", "->string<-");

	printf(BGREEN);
	printf("CRASH?\n");
	printf(BRED);
	printf("%s\n", NULL);
	printf(BBLUE);
	ft_printf("%");
	ft_printf("%+s", NULL);
	ft_printf("aaa%+.0qf", 1.1);
	ft_printf("\n\n");
/*
	printf(BGREEN);
	printf("COLORS\n");
	printf(BRED);
	printf("123{cyan}45{notthis}67{eoc}89%s\n", "testi");
	printf(BRED);
	ft_printf("123{cyan}45{notthis}67{eoc}89%s\n\n", "testi");

	printf(BGREEN);
	printf("BINARY\n");
	printf(BRED);
	ft_printf("8 is %6#b and 255 is %b and 1999 is %b and 1 with width 08# %08b\n\n", 8, 255, 1999, 1);

	printf(BGREEN);
	printf("COLORS\n");
	printf(BRED);
	dprintf(2, "this goes to error output with fd2 %s\n", "testi");
	printf(BRED);
	ft_dprintf(2, "this goes to error output with fd2 %s\n\n", "testi");

	printf(BGREEN);
	char	*rstring;
	printf("RPRINTF (RETURN TO STRING)\n");
	printf(BRED);
	rstring = ft_rprintf("12345%s", "testi");
	printf(BRED);
	printf("string should be \"12345testi\", is \"%s\"\n\n", rstring);

	printf(BGREEN);
	printf("WIDTH OR PRECISION FROM ARGS IF *\n");
	printf(BRED);
	ft_printf("width 8 for this x >%*c< and -8 for this x >%*c< and precision 2 >%.*f< for float\n\n", 8, 'x', -8, 'x', 2, 1.23456);

	printf(BGREEN);
	printf("DIGIT:\n");
	printf(BRED);
	printf("%hhd and %hhd and %hhd and %hhd and %hhhd\n", (char)2147483648, (char)-2147483647, (char)0, (char)123, (short int)-12345);
	ft_printf(BBLUE);
	ft_printf("%hhd and %hhd and %hhd and %hhd and %hhhd\n", (char)2147483648, (char)-2147483647, (char)0, (char)123, (short int)-12345);
*/
//	while(1);
	return (0);
}
