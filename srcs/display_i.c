/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:46:16 by hopham            #+#    #+#             */
/*   Updated: 2019/12/04 19:47:31 by hopham           ###   ########.fr       */
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

static	int		n_size(unsigned int nb)
{
	unsigned int	size;

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

t_printf	*display_i(t_printf *list)
{
	int	i;
	int	i_size;

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
	if (list->flag_convert[3] == '0' && list->precision == -1)
}
