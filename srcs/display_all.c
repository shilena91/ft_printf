/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:41:52 by hopham            #+#    #+#             */
/*   Updated: 2019/12/09 01:31:49 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*display_all(t_printf *list)
{
	char	specifier;

	specifier = list->specifier_char;
	if (specifier == 'c')
		display_c(list);
	else if (specifier == 's')
		display_s(list);
	else if (specifier == 'd' || specifier == 'i')
		display_i(list);
	else if (specifier == 'o')
		display_o(list);
	else if (specifier == 'u')
		display_u(list);
	else if (specifier == 'x' || specifier == 'X')
		display_x(list);
	else if (specifier == 'p')
		display_p(list);
	else if (specifier == 'f')
		display_f(list);
	return (list);
}
