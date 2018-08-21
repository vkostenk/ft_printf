/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 17:48:29 by vkostenk          #+#    #+#             */
/*   Updated: 2018/08/21 13:36:58 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			ft_wstrlen(unsigned *str)
{
	size_t len;

	len = 0;
	while (*str != L'\0')
	{
		len++;
		++str;
	}
	return (len);
}

static char		*ft_wstr_precision(t_format *format, wchar_t *wchar)
{
	char	*str;
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strnew(format->len);
	while (*((unsigned *)wchar) != L'\0')
	{
		temp[i] = *wchar;
		wchar++;
		i++;
	}
	if (format->precision > 0 && format->precision < format->len)
		str = ft_strsub(temp, 0, format->precision);
	else
		str = ft_strsub(temp, 0, format->len);
	free(temp);
	return (str);
}

static char		*ft_width(t_format *format)
{
	int		n;
	char	*str;
	char	insert;

	insert = ' ';
	if (format->precision > 0 && format->precision < format->len)
		n = format->width - format->precision;
	else
		n = format->width - format->len;
	if (n < 0)
		n = 0;
	str = ft_strnew(n);
	ft_memset(str, insert, n);
	return (str);
}

char			*ft_print_wstr(t_format *format, va_list *arg)
{
	char	*temp;
	char	*val_to_print;
	char	*mod_print_val;
	wchar_t *wchar;

	wchar = va_arg(*arg, wchar_t*);
	format->len = (int)(ft_wstrlen((unsigned *)wchar));
	val_to_print = ft_wstr_precision(format, wchar);
	mod_print_val = ft_width(format);
	if (format->flag.minus)
		temp = ft_strjoin(val_to_print, mod_print_val);
	else
		temp = ft_strjoin(mod_print_val, val_to_print);
	format->len = ft_strlen(temp);
	return (temp);
}
