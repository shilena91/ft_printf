/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:57:21 by hopham            #+#    #+#             */
/*   Updated: 2019/12/10 19:25:29 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*display_percent(t_printf *list)
{
	if (list->flag_convert[3] == '0' && list->precision <= 0
		&& !list->flag_convert[0])
	{
		list->precision = list->width;
		list->width = 0;
	}
	if (list->flag_convert[0] != '-')
		display_gap(list, ' ', list->width - 1, 1);
	if (list->flag_convert[3] == '0')
		display_gap(list, '0', list->precision - 1, 1);
	write(1, "%", 1);
	if (list->flag_convert[0] == '-')
		display_gap(list, ' ', list->width - 1, 1);
	list->len++;
	return (list);
}
