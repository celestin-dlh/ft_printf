# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frrobert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 13:26:14 by frrobert          #+#    #+#              #
#    Updated: 2019/02/04 16:00:14 by cdelahay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

NAME = libftprintf.a

#FLAGS =
FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = srcs

DIR_O = obj

HEADER = includes

SOURCES =  check_field_wise.c \
		   checking_format.c \
		   csp_modification.c \
		   csp_summary.c \
		   csp_summary2.c \
		   dioux_modification.c \
		   dioux_summary.c \
		   flag_double_h_dioux.c \
		   flag_double_l_dioux.c \
		   flag_simple_h_dioux.c \
		   flag_simple_l_dioux.c \
		   float_summary.c \
		   ft_printf.c \
		   handler.c \
		   hex_modif.c \
		   no_flag_dioux.c \
		   octal_modif.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	mkdir -p obj
	$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	rm -f $(OBJS)
	rm -rf $(DIR_O)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean re norme all clean

