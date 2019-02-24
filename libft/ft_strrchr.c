/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 07:16:14 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/09 16:18:59 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	int			len;
	const char	*ptr;

	i = 0;
	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (s[len] == (char)c)
		{
			ptr = &s[len];
			return ((char*)ptr);
		}
	}
	return (NULL);
}
