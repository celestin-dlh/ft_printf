/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp_summary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 13:17:07 by frrobert          #+#    #+#             */
/*   Updated: 2019/02/04 16:00:41 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*pourcentage_modif(t_print *data)
{
	char	*variable;

	if (!(variable = ft_strdup("%")))
		exit(EXIT_FAILURE);
	if (data->flag_minus == TRUE)
		variable = create_blank(variable, data->blanks_number);
	else if (data->zero_flag == TRUE)
		variable = create_zeros(variable, data->zeros_number);
	else if (data->field_flag == TRUE)
		variable = create_field(variable, data->field_width);
	return (variable);
}

void		char_nul_two(t_print *data)
{
	char	*variable;

	if (!(variable = ft_strdup("")))
		exit(EXIT_FAILURE);
	variable = create_field(variable, data->field_width - 1);
	ft_putstr(variable);
	write(1, &data->type_char, 1);
	data->length = data->field_width;
	free(variable);
}

char		*char_nul(t_print *data)
{
	char	*variable;
	char	*ret;

	if (!(variable = ft_strdup("")))
		exit(EXIT_FAILURE);
	data->flag_nul = TRUE;
	if (data->flag_minus == TRUE && data->blanks_number != 0)
	{
		write(1, &data->type_char, 1);
		variable = create_blank(variable, data->blanks_number - 1);
		ft_putstr(variable);
		data->length = data->blanks_number;
	}
	else if (data->field_flag == TRUE && data->field_width != 0)
		char_nul_two(data);
	else
	{
		write(1, &data->type_char, 1);
		data->length = 1;
	}
	free(variable);
	if (!(ret = ft_strdup("")))
		exit(EXIT_FAILURE);
	return (ret);
}

char		*csp_summary2(va_list ap, const char *format, t_print *data,
							size_t *i)
{
	char	*variable;
	char	*temp;
	char	*little;

	little = NULL;
	if (format[*i] == 's')
	{
		temp = va_arg(ap, char*);
		if (temp == NULL)
			data->type_string = ft_strdup("(null)");
		else
			data->type_string = ft_strdup(temp);
		if (!data->type_string)
			exit(EXIT_FAILURE);
		variable = create_string(data->type_string, data);
	}
	else
		variable = csp_summary3(ap, data);
	return (variable);
}

char		*csp_summary(va_list ap, const char *format, t_print *data,
							size_t *i)
{
	char	*variable;
	char	*temp;

	if (format[*i] == 'c')
	{
		data->type_char = (char)va_arg(ap, int);
		if (data->type_char == 0)
			variable = char_nul(data);
		else
		{
			if (!(temp = ft_strdup(&data->type_char)))
				exit(EXIT_FAILURE);
			variable = create_char(temp, data);
		}
	}
	else
		variable = csp_summary2(ap, format, data, i);
	return (variable);
}
