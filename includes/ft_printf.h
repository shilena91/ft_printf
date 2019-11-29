/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:26:06 by hopham            #+#    #+#             */
/*   Updated: 2019/11/29 16:34:43 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include "../libft/includes/libft.h"

typedef	struct	s_list
{
	const char	*format;
	va_list		args;
	int			len;
	size_t		i;
	int			width;
	int			precision;
	char		*specifier;
	char		*flags;
	char		*len_arg;
	
}				t_list;


#endif