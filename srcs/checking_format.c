/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:10:22 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/04 15:07:15 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			point_separator2(const char *format, size_t *i, t_print *data)
{
	int		nb_separator;

	data->len = 0;
	while (ft_strchr("0123456789+", format[*i]))
	{
		if (format[*i] == '+')
		{
			data->flag_plus = TRUE;
			data->len = 0;
		}
		data->len++;
		(*i)++;
	}
	if (!(data->type_string = ft_strsub(format, *i - data->len, data->len)))
		exit(EXIT_FAILURE);
	nb_separator = ft_atoi(data->type_string);
	free(data->type_string);
	return (nb_separator);
}

int			point_separator(const char *format, size_t *i, t_print *data)
{
	int		nb_separator;

	nb_separator = 0;
	(*i)++;
	while (ft_strchr("0+#", format[*i]))
	{
		if (format[*i] == '+')
			data->flag_plus = TRUE;
		else if (format[*i] == '#')
			data->flag_diese = TRUE;
		(*i)++;
	}
	if (!ft_strchr("0123456789", format[*i]))
		return (0);
	else
		nb_separator = point_separator2(format, i, data);
	return (nb_separator);
}

void		check_sign3(const char *format, size_t *i, t_print *data)
{
	if (format[*i] == 'L')
	{
		data->flag_l_maj = TRUE;
		(*i)++;
	}
	else
		(*i)++;
}

void		check_sign2(const char *format, size_t *i, t_print *data)
{
	if (format[*i] == ' ' || format[*i] == '#')
	{
		if (format[*i] == ' ')
			data->flag_space = TRUE;
		else if (format[*i] == '#')
			data->flag_diese = TRUE;
		(*i)++;
	}
	else if (format[*i] == 'l')
	{
		if (data->flag_l == TRUE)
			data->flag_double_l = TRUE;
		data->flag_l = TRUE;
		(*i)++;
	}
	else if (format[*i] == 'h')
	{
		if (data->flag_h == TRUE)
			data->flag_double_h = TRUE;
		data->flag_h = TRUE;
		(*i)++;
	}
	else
		check_sign3(format, i, data);
}

void		check_sign(const char *format, size_t *i, t_print *data)
{
	while (ft_strchr("+-0. #lhL", format[*i]))
	{
		if (format[*i] == '+')
		{
			data->flag_plus = TRUE;
			(*i)++;
		}
		else if (format[*i] == '-')
		{
			data->flag_minus = TRUE;
			data->blanks_number = point_separator(format, i, data);
		}
		else if (format[*i] == '0')
		{
			if (data->flag_minus == TRUE)
				data->zero_flag = FALSE;
			else
				data->zero_flag = TRUE;
			data->zeros_number = point_separator(format, i, data);
		}
		else if (format[*i] == '.')
			data->nb_separator = point_separator(format, i, data);
		else
			check_sign2(format, i, data);
	}
}
