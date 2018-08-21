/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_choze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 18:35:26 by vkostenk          #+#    #+#             */
/*   Updated: 2018/08/21 13:49:08 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** asigne link to function by specifier
*/

static void			ft_dashtable(t_fun *f)
{
	f['s'] = &ft_print_str;
	f['S'] = &ft_print_wstr;
	f['p'] = &ft_print_ptr;
	f['d'] = &ft_print_nbr;
	f['D'] = &ft_print_nbr;
	f['i'] = &ft_print_nbr;
	f['o'] = &ft_print_octal;
	f['O'] = &ft_print_octal;
	f['u'] = &ft_print_unbr;
	f['U'] = &ft_print_unbr;
	f['x'] = &ft_print_hex;
	f['X'] = &ft_print_hex;
	f['c'] = &ft_print_char;
	f['C'] = &ft_print_char;
}

/*
** run function by specifier
** and handle some adge case, with width != 0
*/

int					ft_type(t_format *format, va_list *arg)
{
	char	*val;
	t_fun	f;
	int		count;

	f = ft_function(format->specifier);
	if (f)
		val = f(format, arg);
	else if (format->width != 0)
	{
		format->len = format->width;
		val = ft_strnew(format->width);
		ft_memset(val, ' ', format->width);
		count = (format->flag.minus) ? 0 : format->width - 1;
		ft_memset(val + count, format->specifier, 1);
	}
	else
	{
		format->len = 1;
		val = ft_strnew(1);
		ft_memset(val, format->specifier, 1);
	}
	count = write(1, val, format->len);
	ft_memdel((void **)&val);
	return (count);
}

/*
**create table of functions when launch first time
*/

t_fun				ft_function(char c)
{
	static t_fun	*f;
	int				i;

	if (!f)
	{
		f = ft_memalloc(sizeof(*f) * 256);
		if (f)
			ft_dashtable(f);
	}
	i = (int)c;
	return (f[i]);
}
