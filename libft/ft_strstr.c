/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:46:11 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/09 16:17:47 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char*)haystack + i);
		}
		i++;
	}
	return (NULL);
}
