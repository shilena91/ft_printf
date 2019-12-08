/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 23:11:50 by HoangPham         #+#    #+#             */
/*   Updated: 2019/12/09 01:13:11 by HoangPham        ###   ########.fr       */
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

static void         print_leading_zero(uintmax_t num, char hash, char x)
{
    if (num && hash == '#')
    {
        if (x == 'x')
            write(1, "0x", 2);
        if (x == 'X')
            write(1, "0X", 2);
    }
}

static t_printf     *do_x(t_printf *list, char *str, uintmax_t num)
{
    int         num_width;
    int         not_blank;
    
    num_width = ft_strlen(str);
    if (list->flag_convert[4] == '#' && list->flag_convert[3] == '0'
        && list->width && list->precision == -1)
        num_width += 2;
    if (list->flag_convert[3] == '0' && list->precision == -1
        && !list->flag_convert[0])
        list->precision = list->width;
    not_blank = (num_width <= list->precision && list->precision > 0)
                ? list->precision : num_width;
    if (list->flag_convert[4] == '#')
        not_blank += 2;
    list->len += (not_blank <= list->width) ? list->width : not_blank;
    if (list->flag_convert[0] != '-')
        display_gap(list, ' ', list->width - not_blank);
    print_leading_zero(num, list->flag_convert[4], list->specifier_char);
    display_gap(list, '0', list->precision - num_width);
    ft_putstr(str);
    if (list->flag_convert[0] == '-')
        display_gap(list, ' ', list->width - not_blank);
    ft_strdel(&str);
    return (list);
}

t_printf            *display_x(t_printf *list)
{
    char        *str;
    char        c;
    uintmax_t   num;

    num = get_num(list);
    if (num == 0 && list->precision == 0)
    {
        display_gap(list, ' ', list->width);
        return (list);
    }
    c = 'a';
    if (list->specifier_char == 'X')
        c = 'A';
    if (!(str = ft_itoa_base(num, 16, c)))
        exit(-1);
    return (do_x(list, str, num));
}
