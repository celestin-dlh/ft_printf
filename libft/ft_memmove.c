/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 09:19:20 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/09 17:56:05 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*srcs;
	size_t		i;

	dest = dst;
	srcs = src;
	i = 0;
	if (dest > srcs)
	{
		i = len;
		while (i > 0)
		{
			dest[i - 1] = srcs[i - 1];
			i--;
		}
	}
	else if (srcs > dest)
	{
		ft_memcpy(dest, srcs, len);
	}
	return (dst);
}
