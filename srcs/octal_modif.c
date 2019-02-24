/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_modif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:18:15 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/04 15:44:43 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*octal_diese_separator(char *variable, t_print *data)
{
	variable = create_zeros(variable, data->nb_separator);
	if (data->flag_minus == TRUE)
		variable = create_blank(variable, data->blanks_number);
	else if (data->zero_flag == TRUE)
		variable = create_field(variable, data->zeros_number);
	else if (data->field_flag == TRUE)
		variable = create_field(variable, data->field_width);
	return (variable);
}

char		*octal_diese_no_separator(char *variable, t_print *data)
{
	if (data->flag_minus == TRUE)
		variable = create_blank(variable, data->blanks_number);
	else if (data->zero_flag == TRUE)
		variable = create_zeros(variable, data->zeros_number);
	else if (data->field_flag == TRUE)
		variable = create_field(variable, data->field_width);
	return (variable);
}

char		*octal_modif(char *var_string, t_print *data)
{
	char	*variable;
	char	*little;

	variable = var_string;
	if (!(little = ft_strdup("0")))
		exit(EXIT_FAILURE);
	if (data->flag_diese == TRUE)
	{
		variable = zero_flag_addr(variable, little, 0);
		if (data->nb_separator > -1)
			variable = octal_diese_separator(variable, data);
		else
			variable = octal_diese_no_separator(variable, data);
	}
	else
		variable = create_int_summary(variable, data);
	free(little);
	return (variable);
}
