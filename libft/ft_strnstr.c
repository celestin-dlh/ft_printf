/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 06:36:29 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/09 16:18:11 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && (i + j < len))
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
