/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:56:21 by vkostenk          #+#    #+#             */
/*   Updated: 2018/08/21 13:34:40 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_octal_precision(t_format *format, long long n)
{
	char	*temp;
	char	*precision;
	char	*start;
	int		digit;
	int		num;

	temp = ft_itoa_base_uns(n, 8, 'x');
	if (n == 0 && (format->dot || format->flag.hashtag))
		temp = ft_strnew(0);
	num = ft_strlen(temp);
	if (format->precision > num)
		digit = format->precision;
	else
		digit = num;
	precision = ft_strnew(digit + 1);
	start = precision;
	while (format->precision > num++)
		*(precision++) = '0';
	ft_strcpy(precision, temp);
	format->len = ft_strlen(start);
	ft_memdel((void **)&temp);
	return (start);
}

static char			*ft_width(t_format *format)
{
	char	*temp;
	char	*start;
	int		i;
	char	insert;

	insert = ' ';
	if (format->flag.hashtag)
		format->len = format->len + 1;
	if (!format->dot && !format->flag.minus && format->flag.zero)
		insert = '0';
	i = format->width > format->len ? format->width : 0;
	temp = ft_strnew(i + 1);
	start = temp;
	if (i)
	{
		while (i > format->len++)
			*(temp++) = insert;
	}
	return (start);
}

static void			ft_add_ox(t_format *format, char **val, char **modif)
{
	if (format->flag.hashtag)
	{
		if (!format->dot && !format->flag.minus && format->flag.zero)
			*modif = ft_strjoin(ft_strsub("0", 0, 1), *modif);
		else
			*val = ft_strjoin(ft_strsub("0", 0, 1), *val);
	}
	return ;
}

char				*ft_print_octal(t_format *format, va_list *arg)
{
	char					*temp;
	char					*val_to_print;
	char					*mod_print_val;
	unsigned long long int	n;

	n = ft_uconvertflags(format, arg);
	format->len = ft_uint_count(n);
	val_to_print = ft_octal_precision(format, n);
	mod_print_val = ft_width(format);
	ft_add_ox(format, &val_to_print, &mod_print_val);
	if (format->flag.minus)
		temp = ft_strjoin(val_to_print, mod_print_val);
	else
		temp = ft_strjoin(mod_print_val, val_to_print);
	format->len = ft_strlen(temp);
	return (temp);
}
