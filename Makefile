# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/09 07:13:10 by aljigmon          #+#    #+#              #
#    Updated: 2019/07/21 18:02:30 by aljigmon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = src/b.c \
	  src/big_x.c \
	  src/c.c \
	  src/d.c \
	  src/d_2.c \
	  src/flag_wd_pr_d.c \
	  src/f.c \
	  src/ft_atoi.c \
	  src/ft_printf.c \
	  src/init.c \
	  src/init_struct.c \
	  src/isa.c \
	  src/isa_2.c \
	  src/o.c \
	  src/o_2.c \
	  src/p.c \
	  src/parser.c \
	  src/pourcent.c \
	  src/s.c \
	  src/size_nbr.c \
	  src/u.c \
	  src/u_2.c \
	  src/x.c \
	  src/options_xs.c \
	  src/r.c \
	  src/colors.c \
	  src/ft_strrev.c \
	  src/shield_buffer.c \
	  src/send_good_type.c \
	  src/size_number_base.c \
	  src/ft_pow.c \
	  src/print_value_f.c


HEADERS_DIR = headers/

HEADERS = headers/colors.h \
		  headers/ft_atoi.h \
		  headers/ft_printf.h \
		  headers/init.h \
		  headers/init_struct.h \
		  headers/isa.h \
		  headers/parser.h \
		  headers/size_nbr.h \
		  headers/struct.h \
		  headers/types_func.h \
		  headers/ft_strrev.h \
		  headers/shield_buffer.h \
		  headers/send_good_type.h \
		  headers/u_2.h \
		  headers/o_2.h \
		  headers/options_xs.h \
		  headers/size_number_base.h \
		  headers/d_2.h \
		  headers/flag_wd_pr_d.h \
		  headers/ft_pow.h \
		  headers/is_float_neg.h \
		  headers/print_value_f.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[32;1;m$(NAME) generated"

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(HEADERS_DIR)

clean:
	@rm -f $(OBJ)
	@echo "\033[31;1;mObject files deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31;1;m$(NAME) deleted"

re: fclean all

