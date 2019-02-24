/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 09:23:13 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/09 17:51:18 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			*s1;

	i = 0;
	s1 = (char*)s;
	while (i < n)
	{
		if (s1[i] == (char)c)
			return (s1 + i);
		i++;
	}
	return (NULL);
}
