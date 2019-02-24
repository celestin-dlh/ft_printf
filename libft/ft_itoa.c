/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:25:43 by cdelahay          #+#    #+#             */
/*   Updated: 2019/01/15 15:51:31 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_str_len(long long n)
{
	size_t i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(long long int n)
{
	char			*str;
	size_t			len;
	long long int	n_cpy;

	len = get_str_len(n);
	n_cpy = n;
	if (n < 0)
	{
		n_cpy = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = n_cpy % 10 + '0';
	while (n_cpy /= 10)
		str[--len] = n_cpy % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
