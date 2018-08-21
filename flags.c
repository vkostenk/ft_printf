/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:15:33 by vkostenk          #+#    #+#             */
/*   Updated: 2018/08/21 14:03:56 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			ft_convertflags(t_format *format, va_list *arg)
{
	long long n;

	n = 0;
	if (!(ft_strcmp(format->length, "")))
		n = va_arg(*arg, int);
	else if (!(ft_strcmp(format->length, "hh")))
		n = (char)va_arg(*arg, int);
	else if (!(ft_strcmp(format->length, "h")))
		n = (short)va_arg(*arg, int);
	else if (!(ft_strcmp(format->length, "l")))
		n = va_arg(*arg, long);
	else if (!(ft_strcmp(format->length, "ll")))
		n = va_arg(*arg, long long);
	else if (!(ft_strcmp(format->length, "j")))
		n = va_arg(*arg, intmax_t);
	else if (!(ft_strcmp(format->length, "z")))
		n = va_arg(*arg, size_t);
	return (n);
}

unsigned long long	ft_uconvertflags(t_format *format, va_list *arg)
{
	unsigned long long n;

	n = 0;
	if (!(ft_strcmp(format->length, "")))
		n = va_arg(*arg, unsigned int);
	else if (!(ft_strcmp(format->length, "hh")))
		n = (unsigned char)va_arg(*arg, unsigned int);
	else if (!(ft_strcmp(format->length, "h")))
		n = (unsigned short)va_arg(*arg, unsigned int);
	else if (!(ft_strcmp(format->length, "l")))
		n = va_arg(*arg, unsigned long);
	else if (!(ft_strcmp(format->length, "ll")))
		n = va_arg(*arg, unsigned long long);
	else if (!(ft_strcmp(format->length, "j")))
		n = va_arg(*arg, uintmax_t);
	else if (!(ft_strcmp(format->length, "z")))
		n = va_arg(*arg, size_t);
	return (n);
}
