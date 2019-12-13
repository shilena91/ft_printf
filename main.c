/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:35:59 by hopham            #+#    #+#             */
/*   Updated: 2019/12/13 16:19:06 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <float.h>

int	main(void)
{
	int	var;

	char c = 'A';
	//printf("%03o | %#o | %20o | %o | %o | %#7o | %#3o | %#-8.5o\n", 0, 12345, -12345, 2147483647, -2147483647, 33, 33, 0);
	//printf("%u and %u and %20u and %u and %u\n", 0, 12345, -12345, 2147483647, -2147483647);
	//ft_printf("%u and %u and %20u and %u and %u\n", 0, 12345, -12345, 2147483647, -2147483647);
	//ft_printf("%20o", -12345);
	//var = printf("%05");
	//var = printf("%5");
	//ft_putnbr(var);
	//printf("\n");
	
	ft_printf("%-5m\n");
	//printf("\n");
	//printf("%i\n",ft_printf("%-5n"));
	printf("%-5m");
	//printf("%i\n",printf("%-5n"));

}
