/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 15:45:49 by vkostenk          #+#    #+#             */
/*   Updated: 2018/08/21 14:06:43 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_hex_precision(t_format *format, unsigned long long n)
{
	char	*temp;
	char	*precision;
	char	*start;
	int		num;
	int		digit;

	num = ft_uint_count(n);
	temp = ft_itoa_base_uns(n, 16, format->specifier);
	num = ft_strlen(temp);
	if (format->precision > num)
		digit = format->precision;
	else
		digit = num;
	precision = ft_strnew(digit + 1);
	ft_bzero(precision, digit + 1);
	start = precision;
	while (format->precision > num++)
		*(precision++) = '0';
	if (n == 0 && format->dot)
		temp = ft_strsub("", 0, 0);
	ft_strcpy(precision, temp);
	ft_memdel((void**)&temp);
	format->len = ft_strlen(start);
	return (start);
}

static char		*ft_width(t_format *format)
{
	char	*temp;
	char	*start;
	char	insert;
	int		i;

	insert = ' ';
	if (format->flag.hashtag)
		format->len = format->len + 2;
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

static void		ft_add_ox(t_format *format,
		char **val_to_print, char **mod_print_val, unsigned long long n)
{
	if (format->flag.hashtag && n != 0)
	{
		if (!format->dot && !format->flag.minus && format->flag.zero)
		{
			if (format->specifier == 'x')
				*mod_print_val = ft_strjoin(
						ft_strsub("0x", 0, 2), *mod_print_val);
			else
				*mod_print_val = ft_strjoin(
						ft_strsub("0X", 0, 2), *mod_print_val);
		}
		else
		{
			if (format->specifier == 'x')
				*val_to_print = ft_strjoin(
						ft_strsub("0x", 0, 2), *val_to_print);
			else
				*val_to_print = ft_strjoin(
						ft_strsub("0X", 0, 2), *val_to_print);
		}
	}
	return ;
}

char			*ft_print_hex(t_format *format, va_list *arg)
{
	char					*temp;
	char					*val_to_print;
	char					*modif_print_value;
	unsigned long long int	n;

	n = ft_uconvertflags(format, arg);
	format->len = ft_uint_count(n);
	val_to_print = ft_hex_precision(format, n);
	modif_print_value = ft_width(format);
	ft_add_ox(format, &val_to_print, &modif_print_value, n);
	if (format->flag.minus)
		temp = ft_strjoin(val_to_print, modif_print_value);
	else
		temp = ft_strjoin(modif_print_value, val_to_print);
	format->len = ft_strlen(temp);
	return (temp);
}
