/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:35:22 by hopham            #+#    #+#             */
/*   Updated: 2019/12/06 13:40:19 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*display_c(t_printf *list)
{
	char	c;

	c = va_arg(list->args, int);
	if (list->flag_convert[3] == '0' && list->flag_convert[0] != '-')
		display_gap(list, '0', list->width - 1);
	else if (list->flag_convert[0] != '-')
		display_gap(list, ' ', list->width - 1);
	write(1, &c ,1);
	list->len++;
	if (list->flag_convert[0] == '-')
		display_gap(list, ' ', list->width - 1);
	return (list);
}
