/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 16:34:21 by vkostenk          #+#    #+#             */
/*   Updated: 2018/08/20 22:37:08 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	new = ft_strnew(len);
	if (!s)
		return (NULL);
	if (!new)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	return (new);
}
