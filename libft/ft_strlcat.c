/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 07:33:19 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/09 16:21:26 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	dst_length;
	size_t	len;

	if (!(d = (char*)ft_memchr(dst, '\0', size)))
		return (size + ft_strlen(src));
	s = (char*)src;
	d = (char*)dst;
	dst_length = ft_strlen(dst);
	len = dst_length + ft_strlen(s);
	d = d + dst_length;
	while (dst_length++ < size - 1 && s)
		*d++ = *s++;
	*d = '\0';
	return (len);
}
