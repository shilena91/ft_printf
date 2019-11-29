/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdarg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 10:55:30 by hopham            #+#    #+#             */
/*   Updated: 2019/11/29 11:12:50 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	min(int	arg_count, ...)
{
	int	i;
	int	min;
	int	a;
	va_list	ap;

	va_start(ap, arg_count);
	min = va_arg(ap, int);
	i = 2;
	while (i++ < arg_count)
	{
		a = va_arg(ap, int);
		if (a < min)
			min = a;
	}
	va_end(ap);
	return (min);
}

int	main()
{
	int	count = 5;
	printf("Minimum number is: %i", min(count, 12, 6, 7, 67, 1));
	return (0);
}