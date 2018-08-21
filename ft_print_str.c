/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:51:45 by vkostenk          #+#    #+#             */
/*   Updated: 2018/08/21 13:33:00 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_width(t_format *format)
{
	int		n;
	char	*str;
	char	insert;

	insert = ' ';
	if (format->precision > 0 && format->precision < format->len)
		n = format->width - format->precision;
	else if (format->precision == 0 && format->dot)
		n = format->width;
	else
		n = format->width - format->len;
	if (!format->flag.minus && format->flag.zero)
		insert = '0';
	if (n < 0)
		n = 0;
	str = ft_strnew(n);
	ft_memset(str, insert, n);
	return (str);
}

static char		*get_precision_str(t_format *format, char *str)
{
	char *temp;

	if (format->precision > 0 && format->precision < format->len)
		temp = ft_strsub(str, 0, format->precision);
	else if (format->precision == 0 && format->dot)
		temp = ft_strnew(0);
	else
		temp = ft_strsub(str, 0, format->len);
	return (temp);
}

char			*ft_print_str(t_format *format, va_list *arg)
{
	char *str;
	char *val_to_print;
	char *modif_print_value;
	char *temp;

	if (ft_strcmp(format->length, "l"))
	{
		temp = va_arg(*arg, char *);
		if (!temp)
			temp = "(null)";
		format->len = ft_strlen(temp);
		val_to_print = get_precision_str(format, temp);
		modif_print_value = ft_width(format);
		if (format->flag.minus)
			str = ft_strjoin(val_to_print, modif_print_value);
		else
			str = ft_strjoin(modif_print_value, val_to_print);
		format->len = ft_strlen(str);
	}
	else
		str = ft_print_wstr(format, arg);
	return (str);
}
