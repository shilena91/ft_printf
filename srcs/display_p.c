/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:29:38 by HoangPham         #+#    #+#             */
/*   Updated: 2019/12/07 00:01:07 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static		uintmax_t	get_num(t_printf *list)
{
	uintmax_t	nb;

	nb = va_arg(list->args, unsigned long int);
	return (nb);
}

t_printf	*display_p(t_printf *list)
{
	char		*str;
	uintmax_t	num;
	int			not_blank;

	num = get_num(list);
	if (!(str = ft_itoa_base(num, 16, 'a')))
		exit(-1);
	if (list->precision == 0 && num == 0)
		*str = '\0';
	not_blank = ft_strlen(str) + 2;
	list->len += (not_blank <= list->width) ? list->width : not_blank;
	if (list->flag_convert[0] != '-' && list->flag_convert[3] != '0')
		display_gap(list, ' ', list->width - not_blank);
	write(1, "0x", 2);
	if (list->flag_convert[3] == '0')
		display_gap(list, '0', list->width - not_blank);
	ft_putstr(str);
	if (list->flag_convert[0] == '-')
		display_gap(list, ' ', list->width - not_blank);
	ft_strdel(&str);
	return (list);
}
