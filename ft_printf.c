/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:34:32 by vkostenk          #+#    #+#             */
/*   Updated: 2018/08/21 13:27:08 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_delmem(t_format *array)
{
	if (!array)
		return ;
	ft_strdel(&(array->length));
	ft_memdel((void **)&array);
}

int		ft_printf(char *format, ...)
{
	va_list		arg;
	size_t		i;
	size_t		count;
	t_format	*temp;

	va_start(arg, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			count++;
		}
		else
		{
			temp = ft_get_all_flags(format, &arg, &i);
			count += ft_type(temp, &arg);
			ft_delmem(temp);
		}
		i++;
	}
	va_end(arg);
	return (count);
}
