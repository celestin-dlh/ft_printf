/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 09:13:15 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/09 17:55:52 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		i++;
	}
	return (dst);
}
