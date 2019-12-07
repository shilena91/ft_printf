/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:02:04 by HoangPham         #+#    #+#             */
/*   Updated: 2019/12/08 00:41:17 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	get_num(t_printf *list)
{
	uintmax_t	num;

	if (ft_strcmp(list->len_mods_convert, "hh") == 0)
		num = (unsigned char)va_arg(list->args, int);
	else if (ft_strcmp(list->len_mods_convert, "ll") == 0)
		num = (unsigned long long)va_arg(list->args, long long int);
	else if (ft_strcmp(list->len_mods_convert, "h") == 0)
		num = (unsigned short)va_arg(list->args, int);  
	else if (ft_strcmp(list->len_mods_convert, "l") == 0)
		num = (unsigned long)va_arg(list->args, long int);
	else
		num = va_arg(list->args, unsigned int);
	return (num);
}

t_printf			*print_options(t_printf *list, char	*str, uintmax_t num)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str);
	if (list->flag_convert[4] == '#' && num)
		num_width++;
	not_blank = num_width;
	if (num_width <= list->precision)
		not_blank = list->precision;
	list->len += (not_blank <= list->width) ? list->width : not_blank;
	if (list->flag_convert[0] != '-')
		display_gap(list, ' ', list->width - not_blank);
	if (list->flag_convert[4] == '#' && num)
		write(1, "0", 1);
	display_gap(list, '0', list->precision - num_width);
	ft_putstr(str);
	if (list->flag_convert[0] == '-')
		display_gap(list, ' ', list->width - not_blank);
	ft_strdel(&str);
	return (list);
}

t_printf			*display_o(t_printf *list)
{
    char		*str;
	uintmax_t	num;

	num = get_num(list);
	if (num == 0 && list->precision == 0 && list->flag_convert[4] != '#')
	{
		display_gap(list, ' ', list->width);
		return (list);
	}
	if (!(str = ft_itoa_base(num, 8, 'a')))
		exit(-1);
	if (list->flag_convert[3] == '0' && list->precision == -1 && !list->flag_convert[0])
		list->precision = list->width;
	return (print_options(list, str, num));
}
