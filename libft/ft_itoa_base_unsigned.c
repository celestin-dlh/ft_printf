/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:48:51 by cdelahay          #+#    #+#             */
/*   Updated: 2019/01/21 17:00:06 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_unsigned(unsigned long long value, int base)
{
	char				*s;
	unsigned long long	n;
	int					i;

	n = value;
	i = 1;
	while ((n /= base) >= 1)
		i++;
	if (!(s = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	n = value;
	while (i--)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	return (s);
}
