/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:27:22 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/09 17:50:44 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*dest;
	const char	*srcs;
	size_t		i;

	dest = dst;
	srcs = src;
	i = 0;
	while (i < n)
	{
		dest[i] = srcs[i];
		if (srcs[i] == (char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
