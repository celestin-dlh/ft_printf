/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:01:23 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/09 16:20:44 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	size_t	len;
	char	*newstr;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s) + 1;
	if (!(newstr = ft_memalloc(len)))
		return (NULL);
	while (s[i] != '\0')
	{
		newstr[i] = f(s[i]);
		i++;
	}
	return (newstr);
}
