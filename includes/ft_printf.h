/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 16:41:54 by cdelahay          #+#    #+#             */
/*   Updated: 2019/02/04 16:00:01 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define TRUE 1
# define FALSE -1

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct		s_print
{
	int				flag_error;
	int				flag_nul;
	int				flag_diese;
	int				flag_space;
	int				flag_negative;
	int				flag_plus;
	int				flag_separ;
	int				nb_separator;
	int				field_flag;
	int				field_width;
	int				flag_minus;
	int				blanks_number;
	int				zero_flag;
	int				zeros_number;
	int				flag_l;
	int				flag_double_l;
	int				flag_h;
	int				flag_double_h;
	int				flag_l_maj;
	int				len;
	signed char		type_signed_char;
	unsigned char	type_unsigned_char;
	char			type_char;
	char			*type_string;
	int				type_int;
	short			type_short;
	unsigned short	type_unsigned_short;
	int				length;
	unsigned int	type_unsigned_int;
	unsigned long	type_unsigned_long;
	long int		type_long;
	long long int	type_long_long;
}					t_print;

int					point_separator(const char *format, size_t *i,
									t_print *data);
void				check_sign(const char *format, size_t *i, t_print *data);
void				check_field_wise(const char *format, size_t *i,
								t_print *data);
char				*create_zeros(char *variable, int range);
char				*create_blank(char *variable, int range);
char				*create_field(char *variable, int range);
char				*precision(char *variable, int range);
char				*add_sign(char *variable, t_print *data);
char				*zero_flag_addr(char *var, char *little, int range);
char				*float_summary(va_list ap, t_print *data);
char				*hex_modif(char *variable, t_print *data);
char				*octal_modif(char *var_string, t_print *data);
char				*create_int_summary(char *var_string, t_print *data);
char				*no_flag(va_list ap, const char *format, t_print *data,
								size_t *i);
char				*flag_l(va_list ap, const char *format, t_print *data,
								size_t *i);
char				*flag_h(va_list ap, const char *format, t_print *data,
								size_t *i);
char				*flag_double_l(va_list ap, const char *format,
								t_print *data, size_t *i);
char				*flag_double_h(va_list ap, const char *format,
								t_print *data, size_t *i);
char				*dioux_summary(va_list ap, const char *format,
								t_print *data, size_t *i);
char				*create_char(char *var_string, t_print *data);
char				*create_string(char *var_string, t_print *data);
char				*create_addr(char *var_string, t_print *data, char *little);
char				*pourcentage_modif(t_print *data);
char				*csp_summary(va_list ap, const char *format, t_print *data,
								size_t *i);
char				*csp_summary3(va_list ap, t_print *data);
int					ft_printf(const char *format, ...);
#endif
