/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:23:39 by hopham            #+#    #+#             */
/*   Updated: 2019/12/02 18:15:51 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treatment(t_printf *list)
{
	list->i++;
	parse_convert(list);
	parse_field_width(list);
	parse_specifier(list);
	display_all(list);
	return (list->len);	
}
