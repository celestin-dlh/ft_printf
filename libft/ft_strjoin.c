/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:59:34 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/09 16:21:11 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	size_t	len2;
	size_t	i;
	char	*newstr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	if (!(newstr = (char*)malloc(sizeof(char) * (len + len2 + 1))))
		return (NULL);
	newstr = ft_strcpy(newstr, s1);
	while (s2[i] != '\0')
	{
		newstr[len + i] = s2[i];
		i++;
	}
	newstr[len + i] = '\0';
	return (newstr);
}
