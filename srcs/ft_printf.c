/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:58:24 by hopham            #+#    #+#             */
/*   Updated: 2019/12/08 00:34:03 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

t_printf	*initialize(t_printf *list)
{
	list->len = 0;
	list->i = 0;
	list->flags = "0# +-";
	list->specifier_list = "cspdiouxX";
	list->len_mods = "lhL";
	return (list);
}

int	parse(t_printf *list)
{
	if (ft_strcmp(list->format, "%") == 0)
		return (0);
	while (list->format[list->i])
	{
		if (list->format[list->i] == '%')
			treatment(list);
		else
		{
			write(1, &list->format[list->i], 1);
			list->len++;
		}
		list->i++;
	}
	return (list->len);
}

int	ft_printf(const char *format, ...)
{
	t_printf	*list;

	if (!(list = (t_printf*)ft_memalloc(sizeof(t_printf))))
		return (-1);
	list = initialize(list);
	list->format = format;
	if (format)
	{
		va_start(list->args, format);
		list->len = parse(list);
		va_end(list->args);
	}
	free(list);
	return (list->len);
}

int main()
{
	
	//char	c = 'E';
	//char	b = 'B';
	int	*s;
	int	number = 11;
	//char *pointer = "little";
	//s = "123456789";
	//printf("Here is a number %2d and a %s word.\n", number, pointer);
	//printf("%+d \n", number);
	//printf("%-10c, %c", c, b);
    //printf("%-#10x \n", number);  
    //printf("%#X \n", number);
	//printf("% d\n", number);

	//printf("%c\n", 'c');
	printf("%010o\n", number);
	ft_printf("%010o\n", number);
	return(0);
}
