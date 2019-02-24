/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:33:35 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/09 16:25:25 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s_1;
	const unsigned char	*s_2;

	i = 0;
	s_1 = (const unsigned char*)s1;
	s_2 = (const unsigned char*)s2;
	while (n)
	{
		if (*s_1 != *s_2)
			return (*s_1 - *s_2);
		s_1++;
		s_2++;
		n--;
	}
	return (0);
}
