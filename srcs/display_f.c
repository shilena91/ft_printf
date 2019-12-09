/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 01:30:07 by HoangPham         #+#    #+#             */
/*   Updated: 2019/12/09 21:39:32 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static double   get_num(t_printf *list)
{
    double  num;

    if (ft_strcmp(list->len_mods_convert, "L") == 0)
		num = (long double)va_arg(list->args, long double);
	else 
		num = va_arg(list->args, double);
    return (num);
}

static void	place_int(int i_len, char *str, int dec)
{
    i_len--;
	while (i_len > -1)
	{
		str[i_len--] = (dec % 10) + '0';
		dec /= 10;
	}
}

static int	cheap_pow(int val, int pow)
{
	int	ret;

	ret = 1;
	while (pow-- > 0)
		ret *= val;
	return (ret);
}

static char	*ft_ftoa(long double f, int precision, int dot)
{
	uintmax_t	dec;
	uintmax_t	frac;
	char		*str;
	int			dlen;
	uintmax_t	i;
    int         d;
    double      rounding;

    rounding = 0.5;
    d = 0;
    while (d++ < precision)
        rounding /= 10.0;
    f += rounding;
	dec = f;
	frac = precision ? (f - dec) * cheap_pow(10, precision) : 0;
	i = dec;
	dlen = 1;
	while (i > 9 && dlen++)
		i /= 10;
	if (!(str = ft_strnew(dlen + precision + 1)))
		return (0);
	place_int(dlen, str, dec);
	(frac || dot) ? str[dlen++] = '.' : 0;
	i = dlen + precision - 1;
	while (precision-- > 0)
	{
		str[i--] = frac ? (frac % 10) + '0' : '0';
		frac /= 10;
	}
	return (str);
}

t_printf    *display_f(t_printf *list)
{
    char    *nb;
    int     dot;
    double  num;

    num = get_num(list);
	if (list->precision == -1)
		list->precision = 6;
	dot = 0;
	if (list->precision != 0 || list->flag_convert[4] == '#')
		dot = 1;
	if (!(nb = ft_ftoa(num, list->precision, dot)))
		exit(-1);
	ft_putstr(nb);
    return (list);
}
