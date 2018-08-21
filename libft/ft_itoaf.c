/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:50:09 by vkostenk          #+#    #+#             */
/*   Updated: 2018/08/16 17:50:21 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_counter(uintmax_t n)
{
	int			counter;

	counter = 0;
	while (n > 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char			*ft_itoaf(uintmax_t n)
{
	int			counter;
	char		*new;

	if (n == 0)
		return (ft_strdup("0"));
	counter = ft_counter(n);
	if (!(new = ft_strnew(counter)))
		return (NULL);
	while (n > 0)
	{
		new[counter - 1] = n % 10 + '0';
		n = n / 10;
		counter--;
	}
	return (new);
}
