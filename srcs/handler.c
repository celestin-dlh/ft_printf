/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:25:12 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/04 13:48:44 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*create_zeros(char *variable, int range)
{
	int		nb;
	char	*temp;
	char	*zeros_string;

	if ((range - (int)ft_strlen(variable)) > 0)
	{
		nb = range - (int)ft_strlen(variable);
		if (!(zeros_string = (char*)malloc(sizeof(char) * nb + 1)))
			exit(EXIT_FAILURE);
		ft_memset(zeros_string, '0', nb);
		zeros_string[nb] = '\0';
		if (!(temp = ft_strjoin(zeros_string, variable)))
			exit(EXIT_FAILURE);
		free(zeros_string);
		free(variable);
		return (temp);
	}
	return (variable);
}

char		*create_blank(char *variable, int range)
{
	int		nb;
	char	*temp;
	char	*blank_string;

	if ((range - (int)ft_strlen(variable)) > 0)
	{
		nb = range - (int)ft_strlen(variable);
		if (!(blank_string = (char*)malloc(sizeof(char) * nb + 1)))
			exit(EXIT_FAILURE);
		ft_memset(blank_string, ' ', nb);
		blank_string[nb] = '\0';
		if (!(temp = ft_strjoin(variable, blank_string)))
			exit(EXIT_FAILURE);
		free(blank_string);
		free(variable);
		return (temp);
	}
	return (variable);
}

char		*create_field(char *variable, int range)
{
	int		nb;
	char	*temp;
	char	*field_string;

	if ((range - (int)ft_strlen(variable)) > 0)
	{
		nb = range - (int)ft_strlen(variable);
		if (!(field_string = (char*)malloc(sizeof(char) * nb + 1)))
			exit(EXIT_FAILURE);
		ft_memset(field_string, ' ', nb);
		field_string[nb] = '\0';
		if (!(temp = ft_strjoin(field_string, variable)))
			exit(EXIT_FAILURE);
		free(field_string);
		free(variable);
		return (temp);
	}
	return (variable);
}

char		*precision(char *variable, int range)
{
	char	*temp;

	temp = NULL;
	if (range >= 0)
	{
		if (!(temp = ft_strsub(variable, 0, range)))
			exit(EXIT_FAILURE);
		free(variable);
	}
	return (temp);
}

char		*add_sign(char *variable, t_print *data)
{
	char	*sign;
	char	*temp;

	temp = variable;
	if (data->flag_negative == TRUE)
		sign = ft_strdup("-");
	else if (data->flag_plus == TRUE)
		sign = ft_strdup("+");
	else if (data->flag_space == TRUE)
		sign = ft_strdup(" ");
	if (data->flag_negative == TRUE || data->flag_plus == TRUE
			|| data->flag_space == TRUE)
	{
		if (sign == NULL)
			exit(EXIT_FAILURE);
		if (!(temp = ft_strjoin(sign, variable)))
			exit(EXIT_FAILURE);
		free(sign);
		free(variable);
	}
	return (temp);
}
