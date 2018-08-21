/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:51:00 by vkostenk          #+#    #+#             */
/*   Updated: 2018/08/21 13:39:02 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_flag(t_format *format, char **temp, long long n)
{
	if (!format->flag.plus && format->flag.space && n > 0)
		*((*temp)++) = ' ';
	else if (n < 0 && (format->dot || format->flag.minus ||
				!(format->flag.zero)))
		*((*temp)++) = '-';
	else if (format->flag.plus && (format->dot ||
				format->flag.minus || !(format->flag.zero)))
		*((*temp)++) = '+';
	return ;
}

static int			ft_int_count(long long n)
{
	int					i;
	unsigned long long	t;

	if (n == 0)
		return (0);
	t = n;
	if (n < 0)
		t = -t;
	i = 1;
	while (t > 9)
	{
		t /= 10;
		i++;
	}
	return (i);
}

static char			*ft_int_precision(t_format *format, long long n)
{
	int		num;
	int		digits;
	char	*precision;
	char	*start;
	char	*temp;

	num = ft_int_count(n);
	if (format->precision > num)
		digits = format->precision;
	else
		digits = num;
	precision = ft_strnew(digits + 1);
	start = precision;
	ft_flag(format, &precision, n);
	while (format->precision > num++)
		*(precision++) = '0';
	if (n < 0)
		n = n * (-1);
	temp = ft_itoaf(n);
	if (n == 0 && format->dot)
		temp = ft_strsub("", 0, 0);
	ft_strcpy(precision, temp);
	free(temp);
	format->len = ft_strlen(start);
	return (start);
}

static char			*ft_width(t_format *format, long long n)
{
	char	*temp;
	char	*start;
	int		i;
	char	insert;

	insert = ' ';
	if (!format->dot && !format->flag.minus && format->flag.zero)
	{
		insert = '0';
		if (n < 0 || format->flag.space)
			(format->len)++;
	}
	i = format->width > format->len ? format->width : 0;
	temp = ft_strnew(i + 1);
	start = temp;
	if (format->flag.space && !format->flag.plus && insert == '0')
		*(temp)++ = ' ';
	else if (n < 0 && insert == '0')
		*(temp++) = '-';
	else if (format->flag.plus && insert == '0' && format->len++)
		*(temp++) = '+';
	while (i > format->len++)
		*(temp++) = insert;
	return (start);
}

char				*ft_print_nbr(t_format *format, va_list *arg)
{
	char			*temp;
	char			*val_to_print;
	char			*modif_print_value;
	long long int	n;

	if (format->specifier == 'D')
		n = (long long)va_arg(*arg, long long);
	else
		n = ft_convertflags(format, arg);
	format->len = ft_int_count(n);
	if (n < 0 || format->flag.plus || format->flag.space)
		(format->len)++;
	val_to_print = ft_int_precision(format, n);
	modif_print_value = ft_width(format, n);
	if (format->flag.minus)
		temp = ft_strjoin(val_to_print, modif_print_value);
	else
		temp = ft_strjoin(modif_print_value, val_to_print);
	format->len = ft_strlen(temp);
	return (temp);
}
