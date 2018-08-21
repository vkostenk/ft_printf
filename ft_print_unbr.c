/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 18:17:34 by vkostenk          #+#    #+#             */
/*   Updated: 2018/08/21 13:50:57 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_int_count(unsigned long long n)
{
	int					i;
	unsigned long long	t;

	i = 1;
	t = n;
	while (t > 9)
	{
		t = t / 10;
		i++;
	}
	return (i);
}

static char		*ft_width(t_format *format)
{
	char	*temp;
	char	*start;
	int		i;
	int		izero;
	char	insert;

	izero = 0;
	if (!format->dot && !format->flag.minus && format->flag.zero)
		izero = 1;
	i = format->width > format->len ? format->width : 0;
	temp = ft_strnew(i + 1);
	start = temp;
	ft_bzero(temp, i + 1);
	insert = (izero ? '0' : ' ');
	if (i)
		while (i > format->len++)
			*(temp++) = insert;
	return (start);
}

static	char	*ft_uint_precision(t_format *format, long long n)
{
	char	*temp;
	char	*precision;
	char	*start;
	int		digit;
	int		num;

	num = ft_int_count(n);
	if (format->precision > num)
		digit = format->precision;
	else
		digit = num;
	precision = ft_strnew(digit + 1);
	ft_bzero(precision, digit + 1);
	start = precision;
	while (format->precision > num++)
		*(precision++) = '0';
	temp = ft_itoaf(n);
	if (n == 0 && format->dot)
		temp = ft_strsub("", 0, 0);
	ft_strcpy(precision, temp);
	format->len = ft_strlen(start);
	free(temp);
	return (start);
}

char			*ft_print_unbr(t_format *format, va_list *arg)
{
	char					*temp;
	char					*val_to_print;
	char					*mod_print_val;
	unsigned long long int	n;

	if (format->specifier == 'U')
		n = (unsigned long long)va_arg(*arg, unsigned long long);
	else
		n = ft_uconvertflags(format, arg);
	format->len = ft_int_count(n);
	val_to_print = ft_uint_precision(format, n);
	mod_print_val = ft_width(format);
	if (format->flag.minus)
		temp = ft_strjoin(val_to_print, mod_print_val);
	else
		temp = ft_strjoin(mod_print_val, val_to_print);
	format->len = ft_strlen(temp);
	return (temp);
}
