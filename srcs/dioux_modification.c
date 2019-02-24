/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dioux_modification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:05:25 by cdelahay          #+#    #+#             */
/*   Updated: 2019/01/20 17:39:33 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*int_sign_true(char *variable, t_print *data)
{
	if (data->flag_minus == TRUE)
	{
		variable = create_blank(variable, data->blanks_number - 1);
		variable = add_sign(variable, data);
	}
	else if (data->zero_flag == TRUE)
	{
		variable = create_zeros(variable, data->zeros_number - 1);
		variable = add_sign(variable, data);
	}
	else if (data->field_flag == TRUE)
	{
		variable = add_sign(variable, data);
		variable = create_field(variable, data->field_width);
	}
	else
		variable = add_sign(variable, data);
	return (variable);
}

char		*int_sign_false(char *variable, t_print *data)
{
	if (data->flag_minus == TRUE)
		variable = create_blank(variable, data->blanks_number);
	else if (data->zero_flag == TRUE)
		variable = create_zeros(variable, data->zeros_number);
	else if (data->field_flag == TRUE)
		variable = create_field(variable, data->field_width);
	return (variable);
}

char		*create_int_summary(char *var_string, t_print *data)
{
	char	*variable;

	variable = var_string;
	if (data->nb_separator > -1)
	{
		variable = create_zeros(variable, data->nb_separator);
		variable = add_sign(variable, data);
		if (data->flag_minus == TRUE)
			variable = create_blank(variable, data->blanks_number);
		else if (data->zero_flag == TRUE)
			variable = create_field(variable, data->zeros_number);
		else if (data->field_flag == TRUE)
			variable = create_field(variable, data->field_width);
	}
	else
	{
		if (data->flag_negative == TRUE || data->flag_plus == TRUE ||
				data->flag_space == TRUE)
			variable = int_sign_true(variable, data);
		else
			variable = int_sign_false(variable, data);
	}
	return (variable);
}
