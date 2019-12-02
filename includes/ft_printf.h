/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:26:06 by hopham            #+#    #+#             */
/*   Updated: 2019/12/02 17:57:02 by hopham           ###   ########.fr       */
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
	char		*len_arg;
	
}				t_printf;

int			ft_printf(const char *format, ...);
t_printf	*parse_convert(t_printf *list);
t_printf	*parse_field_width(t_printf *list);
t_printf	*parse_specifier(t_printf *list);
int			treatment(t_printf *list);
void		display_gap(t_printf *list, char c, int len);
t_printf	*display_c(t_printf *list);
t_printf	*display_all(t_printf *list);


#endif