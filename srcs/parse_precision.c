/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 10:43:50 by hopham            #+#    #+#             */
/*   Updated: 2019/12/10 17:51:42 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*parse_precision(t_printf *list)
{
	list->precision = -1;
	while (list->format[list->i] == '.')
	{
		list->i++;
		list->precision = 0;
	}
	while (list->format[list->i] >= '0' && list->format[list->i] <= '9')
	{
		list->precision = list->precision * 10 + (list->format[list->i] - 48);
		list->i++;
	}
	return (list);
}
