/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:12:35 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/08 19:20:55 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t length_src;
	size_t i;

	length_src = ft_strlen(src);
	i = 0;
	if (src[0] == '\0')
		while (i < len)
		{
			dst[i] = '\0';
			i++;
		}
	while (i < length_src && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (len > length_src)
	{
		dst[i] = '\0';
		i++;
		len--;
	}
	if (i < len)
		dst[i] = '\0';
	return (dst);
}
