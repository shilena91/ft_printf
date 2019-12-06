/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:26:06 by hopham            #+#    #+#             */
/*   Updated: 2019/12/06 23:11:53 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

typedef	struct	s_printf
{
	const char	*format;
	va_list		args;
	int			len;
	size_t		i;
	int			width;
	int			precision;
	char		*specifier_list;
	char		specifier_char;
	char		*flags;
	char		flag_convert[6];
	char		*len_mods;
	char		len_mods_convert[2];
	
}				t_printf;

int			ft_printf(const char *format, ...);
t_printf	*parse_convert(t_printf *list);
t_printf	*parse_field_width(t_printf *list);
t_printf	*parse_specifier(t_printf *list);
t_printf	*parse_precision(t_printf *list);
t_printf	*parse_len_mod(t_printf *list);
int			treatment(t_printf *list);
void		display_gap(t_printf *list, char c, int len);
t_printf	*display_c(t_printf *list);
t_printf	*display_s(t_printf *list);
t_printf	*display_i(t_printf *list);
t_printf    *display_p(t_printf *list);
t_printf	*display_all(t_printf *list);
char		*ft_itoa_base(uintmax_t num, int base, char c);


#endif