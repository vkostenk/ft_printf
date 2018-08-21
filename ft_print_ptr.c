/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 14:06:26 by vkostenk          #+#    #+#             */
/*   Updated: 2018/08/21 14:03:28 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_add_ox(t_format *format, char **val_to_print,
		char **mod_print_val)
{
	if (!format->dot && !format->flag.minus && format->flag.zero)
		*mod_print_val = ft_strjoin(ft_strsub("0x", 0, 2), *mod_print_val);
	else
		*val_to_print = ft_strjoin(ft_strsub("0x", 0, 2), *val_to_print);
	return ;
}

static char				*ft_width(t_format *format)
{
	char	*temp;
	char	*start;
	char	insert;
	int		i;
	int		izero;

	izero = 0;
	if (!format->dot && !format->flag.minus && format->flag.zero)
		izero = 1;
	i = format->width > format->len ? format->width : 0;
	temp = ft_strnew(i + 1);
	start = temp;
	insert = (izero ? '0' : ' ');
	if (i)
		while (i > format->len++)
			*(temp++) = insert;
	return (start);
}

static char				*ft_ptr_precision(t_format *format, long long n)
{
	char	*temp;
	char	*precision;
	char	*start;
	int		digit;
	int		num;

	num = ft_uint_count(n);
	temp = ft_itoa_base_uns(n, 16, 'x');
	if (n == 0 && format->dot)
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
	if (n < 0)
		n = -n;
	ft_strcpy(precision, temp);
	format->len = ft_strlen(start) + 2;
	ft_memdel((void*)&temp);
	return (start);
}

char					*ft_print_ptr(t_format *format, va_list *arg)
{
	char					*temp;
	char					*val_to_print;
	char					*mod_print_val;
	unsigned long long int	n;
	void					*p;

	p = va_arg(*arg, void*);
	n = (unsigned long long)p;
	format->len = ft_uint_count(n);
	val_to_print = ft_ptr_precision(format, n);
	mod_print_val = ft_width(format);
	ft_add_ox(format, &val_to_print, &mod_print_val);
	if (format->flag.minus)
		temp = ft_strjoin(val_to_print, mod_print_val);
	else
		temp = ft_strjoin(mod_print_val, val_to_print);
	return (temp);
}
