/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:58:24 by hopham            #+#    #+#             */
/*   Updated: 2019/11/29 17:11:17 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

t_list	*initialize(t_list *list)
{
	list->len = 0;
	list->i = 0;
	list->flags = "0# +-";
	list->specifier = "cspdiouxX";
	list->len_arg = "lh";
	return (list);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_list	*list;

	if (!(list = (t_list*)ft_memalloc(sizeof(t_list))))
		return (-1);
	list = initialize(list);
	if (format)
	{
		va_start(list->args, format);
		va_end(list->args);
	}
	free(list);
	return (list->len);
	
}

int main()
{
	int	number = 20 - 30;
	//char *pointer = "little";

	//printf("Here is a number %2d and a %s word.", number, pointer);
	printf("%+d \n", number);
	printf("%-10d \n", number);
    printf("%-#10x \n", number);  
    printf("%#X \n", number);
	printf("% d\n", number);
	return(0);
}
