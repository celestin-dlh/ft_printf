/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:40:09 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/04 15:43:58 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*var_to_string(const char *format, va_list ap, size_t *i,
		t_print *data)
{
	char	*variable;

	variable = NULL;
	if (ft_strchr("csp", format[*i]))
		variable = csp_summary(ap, format, data, i);
	else if (ft_strchr("diouxX", format[*i]))
		variable = dioux_summary(ap, format, data, i);
	else if (ft_strchr("Llf", format[*i]))
		variable = float_summary(ap, data);
	else if (format[*i] == '%')
		variable = pourcentage_modif(data);
	else
	{
		va_arg(ap, int);
		variable = ft_strdup(" ");
	}
	(*i)++;
	return (variable);
}

void		check_format(const char *format, size_t *i, t_print *data)
{
	(*i)++;
	data->flag_nul = FALSE;
	data->length = 0;
	data->flag_diese = FALSE;
	data->flag_space = FALSE;
	data->nb_separator = FALSE;
	data->flag_minus = FALSE;
	data->zero_flag = FALSE;
	data->field_flag = FALSE;
	data->flag_negative = FALSE;
	data->flag_plus = FALSE;
	data->flag_l = FALSE;
	data->flag_h = FALSE;
	data->flag_double_l = FALSE;
	data->flag_double_h = FALSE;
	data->flag_l_maj = FALSE;
	data->flag_error = FALSE;
	check_field_wise(format, i, data);
	check_sign(format, i, data);
}

int			parcing(va_list ap, const char *format, t_print *data)
{
	size_t	i;
	int		len;
	char	*variable;

	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			check_format(format, &i, data);
			variable = var_to_string(format, ap, &i, data);
			len += data->length;
			len += ft_strlen(variable);
			ft_putstr(variable);
			free(variable);
		}
		else
		{
			ft_putchar(format[i]);
			i++;
			len++;
		}
	}
	return (data->flag_error == TRUE ? -1 : len);
}

int			ft_printf(const char *format, ...)
{
	t_print data;
	int		ret;
	va_list	ap;

	bzero(&data, sizeof(t_print));
	va_start(ap, format);
	ret = parcing(ap, format, &data);
	va_end(ap);
	return (ret);
}
