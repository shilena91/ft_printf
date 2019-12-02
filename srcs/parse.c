/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:29:13 by hopham            #+#    #+#             */
/*   Updated: 2019/12/02 14:47:52 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*parse_field_width(t_printf *list)
{
	list->width = 0;
	while (list->format[list->i] >= '0' && list->format[list->i] <= '9')
	{
		list->width = list->width * 10 + (list->format[list->i] - 48);
		list->i++;
	}
	return (list);
}

t_printf	*parse_specifier(t_printf *list)
{
	size_t	j;

	j = 0;
	while (list->specifier_list[j])
	{
		if (list->format[list->i] == list->specifier_list[j])
			list->specifier_char = list->specifier_list[j];
		j++;
	}
	return (list);
}
