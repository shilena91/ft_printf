/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 22:42:10 by HoangPham         #+#    #+#             */
/*   Updated: 2019/12/08 23:27:27 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	get_num(t_printf *list)
{
	uintmax_t	num;

	if (ft_strcmp(list->len_mods_convert, "hh") == 0)
		num = (unsigned char)va_arg(list->args, unsigned int);
	else if (ft_strcmp(list->len_mods_convert, "ll") == 0)
		num = (unsigned long long)va_arg(list->args, unsigned long long int);
	else if (ft_strcmp(list->len_mods_convert, "h") == 0)
		num = (unsigned short)va_arg(list->args, unsigned int);  
	else if (ft_strcmp(list->len_mods_convert, "l") == 0)
		num = (unsigned long)va_arg(list->args, unsigned long int);
	else
		num = va_arg(list->args, unsigned int);
	return (num);
}

static int  n_size(uintmax_t num)
{
    int size;

    size = 0;
    while (num >= 10)
    {
        num /= 10;
        size++;
    }
    return (size + 1);
}

t_printf    *display_u(t_printf *list)
{
    uintmax_t   num;
    int         num_width;
    int         not_blank;

    num = get_num(list);
    if (num == 0 && list->precision == 0)
    {
        display_gap(list, ' ', list->width);
        return (list);
    }
    num_width = n_size(num);
    if (list->flag_convert[3] == '0' && list->precision == -1 &&
        !list->flag_convert[0])
        list->precision = list->width;
    not_blank = num_width;
    if (num_width <= list->precision)
        not_blank = list->precision;
    list->len += (not_blank <= list->width) ? list->width : not_blank;
    if (list->flag_convert[0] != '-')
        display_gap(list, ' ', list->width - not_blank);
    display_gap(list, '0', list->precision - num_width);
    ft_putnbr(num);
    if (list->flag_convert[0] == '-')
        display_gap(list, ' ', list->width - not_blank);
    return (list);
}
