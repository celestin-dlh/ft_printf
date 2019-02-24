/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 09:26:23 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/11 12:51:50 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*zone;

	i = 0;
	if (size <= 0)
		return (NULL);
	if (!(zone = (char*)malloc(sizeof(*zone) * size)))
		return (NULL);
	while (i < size)
		zone[i++] = 0;
	return (zone);
}
