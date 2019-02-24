/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dioux_summary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 13:17:16 by frrobert          #+#    #+#             */
/*   Updated: 2019/01/18 15:49:02 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*dioux_summary(va_list ap, const char *format, t_print *data,
		size_t *i)
{
	char	*variable;

	if (data->flag_double_l == TRUE)
		variable = flag_double_l(ap, format, data, i);
	else if (data->flag_double_h == TRUE)
		variable = flag_double_h(ap, format, data, i);
	else if (data->flag_l == TRUE)
		variable = flag_l(ap, format, data, i);
	else if (data->flag_h == TRUE)
		variable = flag_h(ap, format, data, i);
	else
		variable = no_flag(ap, format, data, i);
	return (variable);
}
