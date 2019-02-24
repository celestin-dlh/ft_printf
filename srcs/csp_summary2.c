/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp_summary2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:59:15 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/04 15:59:49 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*csp_summary3(va_list ap, t_print *data)
{
	char	*variable;
	char	*temp;
	char	*little;

	little = NULL;
	data->type_long = va_arg(ap, long);
	if (data->type_long == 0 && data->nb_separator == 0)
		temp = ft_strdup("");
	else
		temp = ft_itoa_base(data->type_long, 16);
	if (!temp)
		exit(EXIT_FAILURE);
	variable = create_addr(ft_lower(temp), data, little);
	return (variable);
}
