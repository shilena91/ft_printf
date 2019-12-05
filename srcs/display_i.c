/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:46:16 by hopham            #+#    #+#             */
/*   Updated: 2019/12/05 23:26:16 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_num(t_printf *list)
{
	int	num;

	if (ft_strcmp(list->len_mods_convert, "hh") == 0)
		num = (signed char)va_arg(list->args, int);
	else if (ft_strcmp(list->len_mods_convert, "ll") == 0)
		num = (long long)va_arg(list->args, long long int);
	else if (ft_strcmp(list->len_mods_convert, "h") == 0)
		num = (short)va_arg(list->args, int);
	else if (ft_strcmp(list->len_mods_convert, "l") == 0)
		num = (long)va_arg(list->args, long int);
	else
		num = va_arg(list->args, int);
	return (num);
}

static	int		n_size(int nb)
{
	int	size;

	if (nb < 0)
		nb = nb * -1;
	size = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		size++;
	}
	return (size + 1);
}

static char	get_sign(t_printf *list, int nb)
{
	if (nb < 0)
		return ('-');
	if (list->flag_convert[1] == '+')
		return ('+');
	if (list->flag_convert[2] == ' ')
		return (' ');
	return ('\0');
}

static t_printf	*do_options(t_printf *list, int	i_size, int i)
{
	int		not_blank;
	char	sign;

	not_blank = i_size;
	sign = get_sign(list, i);
	i *= (i < 0) ? -1 : 1;
	if (i_size <= list->precision)
		not_blank = list->precision;
	if (sign)
		not_blank++;
	if (list->flag_convert[0] != '-')
		display_gap(list, ' ', list->width - not_blank);
	if (sign)
		write(1, &sign, 1);
	display_gap(list, '0', list->precision - i_size);
	ft_putnbr(i);
	if (list->flag_convert[0] == '-')
		display_gap(list, ' ', list->width - not_blank);
	return (list);
}

t_printf	*display_i(t_printf *list)
{
	int		i;
	int		i_size;

	i = get_num(list);
	if (i == 0 && list->precision == 0)
	{
		if (list->flag_convert[0] != '-')
			display_gap(list, ' ', list->width - 1);
		if (list->flag_convert[1] == '+')
			write(1, "+", 1);
		else if (list->flag_convert[2] == ' ')
			write(1, " ", 1);
		if (list->flag_convert[0] == '-')
			display_gap(list, ' ', list->width - 1);
		return (list);
	}
	i_size = n_size(i);
	if (list->flag_convert[3] == '0' && list->precision == -1 && !list->flag_convert[0])
	{
		list->precision = list->width;
		if (i < 0 || list->flag_convert[1] || list->flag_convert[2])
			list->precision--;
	}
	return (do_options(list, i_size, i));
}	
