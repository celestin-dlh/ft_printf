/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:19:07 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/04 15:05:28 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_float_neg_zero(char *res)
{
	char	*res2;

	if (!(res2 = ft_strjoin("-", res)))
		exit(EXIT_FAILURE);
	free(res);
	return (res2);
}

static char		*ft_float_itoa_general(long double number, int afterpoint,
										long entier, int neg)
{
	char	*res;
	char	*temp_int;
	char	*temp_float;

	number += 1;
	number = number * ft_power(10, afterpoint + 1);
	number += 5;
	number /= 10;
	temp_float = ft_itoa((int)number);
	if (temp_float[0] == '2')
	{
		if (neg == -1)
			entier--;
		else
			entier++;
	}
	temp_int = ft_itoa(entier);
	temp_float[0] = '.';
	if (!(res = ft_strjoin(temp_int, temp_float)))
		exit(EXIT_FAILURE);
	free(temp_int);
	free(temp_float);
	if (neg == -1 && res[0] != '-')
		res = ft_float_neg_zero(res);
	return (res);
}

char			*ft_float_itoa(long double number, int afterpoint)
{
	long		entier;
	int			neg;

	neg = 0;
	entier = (int)number;
	if (number < 0)
		neg = -1;
	if (afterpoint <= 0)
		return (ft_itoa(entier));
	number = number - entier;
	if (neg == -1)
	{
		neg = -1;
		number *= -1;
		return (ft_float_itoa_general(number, afterpoint, entier, neg));
	}
	else if (number == 0)
	{
		return (ft_float_itoa_general(number, afterpoint, entier, neg));
	}
	else
		return (ft_float_itoa_general(number, afterpoint, entier, neg));
}
