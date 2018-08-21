/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:38:25 by vkostenk          #+#    #+#             */
/*   Updated: 2018/08/16 18:22:32 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*res(int i, unsigned long long *convert, char c)
{
	int			n;
	char		*base_x;
	char		*base_for_x;
	char		*res;

	n = 0;
	base_for_x = "0123456789ABCDEF";
	base_x = "0123456789abcdef";
	res = ft_strnew(sizeof(char) * i);
	i--;
	while (i >= 0)
	{
		if (c == 'x')
			res[n] = base_x[convert[i]];
		if (c == 'X')
			res[n] = base_for_x[convert[i]];
		n++;
		i--;
	}
	return (res);
}

char		*ft_itoa_base_uns(unsigned long long value, int base, char c)
{
	int					i;
	unsigned long long	convert[64];

	i = 0;
	if (value == 0)
		return (ft_strsub("0", 0, 1));
	while (value != 0)
	{
		convert[i++] = value % base;
		value = value / base;
	}
	return (res(i, convert, c));
}
