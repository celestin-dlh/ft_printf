/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:58:42 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/09 16:22:43 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int			length;
	int			i;
	char		*dest;

	i = 0;
	length = ft_strlen(s1) + 1;
	if (!(dest = malloc(sizeof(char) * length)))
		return (NULL);
	if (length > 0)
		ft_strcpy(dest, s1);
	return (dest);
}
