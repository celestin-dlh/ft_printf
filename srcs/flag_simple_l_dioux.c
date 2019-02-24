/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_simple_dioux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:16:42 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/04 14:01:59 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*flag_l_d(va_list ap, t_print *data)
{
	char	*variable;
	char	*temp;

	data->type_long = va_arg(ap, long);
	if (data->type_long == (-9223372036854775807 - 1))
	{
		temp = ft_strdup("9223372036854775808");
		data->flag_negative = TRUE;
		variable = create_int_summary(temp, data);
		return (variable);
	}
	else if (data->type_long < 0)
	{
		data->type_long *= -1;
		data->flag_negative = TRUE;
	}
	if (data->type_long == 0 && data->nb_separator == 0)
		temp = ft_strdup("");
	else
		temp = ft_itoa(data->type_long);
	if (temp == NULL)
		exit(EXIT_FAILURE);
	variable = create_int_summary(temp, data);
	return (variable);
}

char		*flag_l_u(va_list ap, t_print *data)
{
	char	*variable;
	char	*temp;

	data->flag_negative = FALSE;
	data->flag_plus = FALSE;
	data->flag_space = FALSE;
	data->type_unsigned_long = (unsigned long)va_arg(ap, unsigned long);
	temp = ft_itoa_unsigned_long(data->type_unsigned_long);
	if (temp == NULL)
		exit(EXIT_FAILURE);
	variable = create_int_summary(temp, data);
	return (variable);
}

char		*flag_l_o(va_list ap, t_print *data)
{
	char	*variable;
	char	*temp;

	data->type_unsigned_long = va_arg(ap, unsigned long);
	if (data->type_unsigned_long == 0 && data->nb_separator == FALSE)
		data->flag_diese = FALSE;
	if (data->type_unsigned_long == 0 && (data->nb_separator == 1
				|| data->nb_separator == 0))
		temp = ft_strdup("");
	else
		temp = ft_itoa_base_unsigned(data->type_unsigned_long, 8);
	if (temp == NULL)
		exit(EXIT_FAILURE);
	variable = octal_modif(temp, data);
	return (variable);
}

char		*flag_l_x(va_list ap, t_print *data)
{
	char	*variable;
	char	*temp;

	data->type_unsigned_long = va_arg(ap, unsigned long);
	if (data->type_unsigned_long == 0)
		data->flag_diese = FALSE;
	if (data->type_unsigned_long == 0 && data->nb_separator == FALSE)
		temp = ft_strdup("0");
	else if (data->type_unsigned_long == 0 && data->nb_separator <= 0)
		temp = ft_strdup("");
	else
		temp = ft_itoa_base_unsigned(data->type_unsigned_long, 16);
	if (temp == NULL)
		exit(EXIT_FAILURE);
	variable = hex_modif(temp, data);
	return (variable);
}

char		*flag_l(va_list ap, const char *format, t_print *data, size_t *i)
{
	char	*variable;

	variable = NULL;
	if (format[*i] == 'd' || format[*i] == 'i')
		variable = flag_l_d(ap, data);
	else if (format[*i] == 'u')
		variable = flag_l_u(ap, data);
	else if (format[*i] == 'o')
		variable = flag_l_o(ap, data);
	else if (format[*i] == 'x' || format[*i] == 'X')
	{
		variable = flag_l_x(ap, data);
		if (format[*i] == 'x')
			variable = ft_lower(variable);
	}
	return (variable);
}
