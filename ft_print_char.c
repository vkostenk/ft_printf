/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 15:14:34 by vkostenk          #+#    #+#             */
/*   Updated: 2018/08/21 13:28:29 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_width(t_format *format)
{
	int		n;
	char	*str;
	char	insert;

	insert = ' ';
	n = format->width - format->len;
	if (n < 0)
		n = 0;
	if (!format->flag.minus && format->flag.zero)
		insert = '0';
	str = ft_strnew(n);
	ft_memset(str, insert, n);
	return (str);
}

char		*ft_print_char(t_format *format, va_list *arg)
{
	char *str;
	char *insert;
	char temp;

	if (format->specifier != '%')
		temp = (char)va_arg(*arg, int);
	else
		temp = '%';
	format->len = 1;
	insert = ft_width(format);
	str = ft_strnew(ft_strlen(insert) + 1);
	if (format->flag.minus)
	{
		*(str) = temp;
		ft_strcpy(str + 1, insert);
	}
	else
	{
		ft_strcpy(str, insert);
		str[ft_strlen(insert)] = temp;
	}
	ft_memdel((void**)&insert);
	format->len = (!temp) ? ft_strlen(str) + 1 : ft_strlen(str);
	return (str);
}
