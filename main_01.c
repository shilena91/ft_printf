/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:35:59 by hopham            #+#    #+#             */
/*   Updated: 2019/12/11 23:40:19 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	var;

	//printf("%03o | %#o | %20o | %o | %o | %#7o | %#3o | %#-8.5o\n", 0, 12345, -12345, 2147483647, -2147483647, 33, 33, 0);
	//printf("%u and %u and %20u and %u and %u\n", 0, 12345, -12345, 2147483647, -2147483647);
	//ft_printf("%u and %u and %20u and %u and %u\n", 0, 12345, -12345, 2147483647, -2147483647);
	//ft_printf("%20o", -12345);
	var = printf("%+5.i\n", 0);
	//ft_putnbr(var);
	var = ft_printf("%+5.d", 0);
	//write(1, "\n", 1);
	//ft_putnbr(var);
}