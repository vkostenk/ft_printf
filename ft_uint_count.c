/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 18:45:41 by vkostenk          #+#    #+#             */
/*   Updated: 2018/08/21 13:20:54 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_uint_count(long long n)
{
	int					i;
	unsigned long long	t;

	t = n;
	i = 0;
	while (t > 9)
	{
		t /= 10;
		i++;
	}
	return (i);
}
