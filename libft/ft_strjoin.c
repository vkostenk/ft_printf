/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:06:52 by vkostenk          #+#    #+#             */
/*   Updated: 2018/08/20 22:35:34 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = (char *)malloc(len1 + len2 + 2);
	ft_bzero(dst, len1 + len2 + 2);
	if (!dst)
		return (NULL);
	ft_strcpy(dst, s1);
	ft_strcat(dst, s2);
	ft_memdel((void **)&s1);
	ft_memdel((void **)&s2);
	return (dst);
}
