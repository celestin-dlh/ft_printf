/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:24:04 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/07 11:05:15 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		length;
	size_t	i;

	length = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		s1[length + i] = s2[i];
		i++;
	}
	s1[length + i] = '\0';
	return (s1);
}
