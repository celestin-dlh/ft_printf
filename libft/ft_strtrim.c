/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:29:58 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/10 18:53:12 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = -1;
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
		len--;
	if (len <= 0)
		len = 0;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	s = s + i;
	i = -1;
	while (++i < len)
	{
		str[i] = *s++;
	}
	str[i] = '\0';
	return (str);
}
