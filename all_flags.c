/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 15:27:05 by vkostenk          #+#    #+#             */
/*   Updated: 2018/08/21 13:55:48 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format			*ft_get_all_flags(char *format, va_list *arg, size_t *i)
{
	t_format *temp;

	temp = malloc(sizeof(t_format));
	ft_bzero(temp, sizeof(t_format));
	temp->flag = ft_get_first_flag(format, i);
	temp->width = ft_get_width(format, i, arg, temp);
	temp->precision = ft_get_precision(format, i, arg, temp);
	temp->length = ft_get_length(format, i);
	temp->specifier = format[(*i)];
	return (temp);
}

/*
** temp->specifier = format[*i] not format[i]
** array subscript is not an integer
*/

t_flag				ft_get_first_flag(char *format, size_t *i)
{
	t_flag temp;

	ft_bzero(&temp, sizeof(t_flag));
	(*i)++;
	while (format[*i] == '+' || format[*i] == '-' ||
			format[*i] == '#' || format[*i] == ' ' || format[*i] == '0')
	{
		if (format[*i] == '-')
			temp.minus = 1;
		if (format[*i] == '+')
			temp.plus = 1;
		if (format[*i] == ' ')
			temp.space = 1;
		if (format[*i] == '0')
			temp.zero = 1;
		if (format[*i] == '#')
			temp.hashtag = 1;
		(*i)++;
	}
	return (temp);
}

int					ft_get_width(char *format, size_t *i, va_list *arg,
		t_format *allflagsstruct)
{
	int		width;
	size_t	j;

	j = *i;
	while (ft_isdigit(format[*i]))
		(*i)++;
	if (format[(*i)] == '*')
	{
		width = va_arg(*arg, int);
		if (width < 0)
		{
			width *= -1;
			allflagsstruct->flag.minus = 1;
		}
		(*i)++;
	}
	else
		width = ft_atoi(format + j);
	return (width);
}

int					ft_get_precision(char *format, size_t *i, va_list *arg,
		t_format *allflagsstruct)
{
	int precision;
	int j;

	precision = 0;
	if (format[(*i)] == '.')
	{
		allflagsstruct->dot = 1;
		(*i)++;
		j = *i;
		while (ft_isdigit(format[(*i)]))
			(*i)++;
		if (format[(*i)] == '*')
		{
			precision = va_arg(*arg, int);
			if (precision < 0)
			{
				precision *= -1;
				allflagsstruct->flag.minus = 1;
			}
			(*i)++;
		}
		else
			precision = ft_atoi(format + j);
	}
	return (precision);
}

char				*ft_get_length(char *format, size_t *i)
{
	char *length;

	length = ft_strnew(2);
	if (format[*i] == 'j' || format[*i] == 'z' || format[*i] == 't' ||
			format[*i] == 'h' || format[*i] == 'l')
	{
		*length = format[(*i)++];
		if (format[*i] == 'l' || format[*i] == 'h')
		{
			*(++length) = format[*i];
			(*i)++;
			length--;
		}
	}
	return (length);
}
