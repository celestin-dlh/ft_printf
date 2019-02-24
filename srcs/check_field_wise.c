/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_field_wise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 17:59:57 by cdelahay          #+#    #+#             */
/*   Updated: 2019/01/21 13:06:01 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		check_field_wise2(const char *format, size_t *i, t_print *data)
{
	if (ft_strchr("123456789", format[*i]))
	{
		(*i)--;
		data->field_width = point_separator(format, i, data);
		data->field_flag = TRUE;
	}
}

void		check_field_wise(const char *format, size_t *i, t_print *data)
{
	while (ft_strchr("# +lh", format[*i]))
	{
		if (format[*i] == '+')
			data->flag_plus = TRUE;
		else if (format[*i] == '#')
			data->flag_diese = TRUE;
		else if (format[*i] == ' ')
			data->flag_space = TRUE;
		else if (format[*i] == 'l')
		{
			if (data->flag_l == TRUE)
				data->flag_double_l = TRUE;
			data->flag_l = TRUE;
		}
		else if (format[*i] == 'h')
		{
			if (data->flag_h == TRUE)
				data->flag_double_h = TRUE;
			data->flag_h = TRUE;
		}
		else if (format[*i] == 'L')
			data->flag_l_maj = TRUE;
		(*i)++;
	}
	check_field_wise2(format, i, data);
}
