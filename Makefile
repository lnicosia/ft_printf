# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 15:56:21 by lnicosia          #+#    #+#              #
#    Updated: 2019/02/27 16:48:29 by gaerhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

MAKEFILE = Makefile

SRC_DIR = src
OBJ_DIR = obj
INCLUDES_DIR = includes
BIN_DIR = .

SRC_RAW = pf_putchar.c pf_putstr.c ft_printf.c pf_putnbr.c pf_putunbr.c \
		  pf_putaddr.c pf_putnbr_base.c pf_invalid.c pf_putpercent.c \
		  pf_putlong_base.c parse_flags.c pf_atoi.c put_padding.c pf_putfloat.c\
		  pf_strnequ.c parse_colors.c base_utils.c pf_float_padding.c \
		  putfloat_utils.c parse_functions.c ft_dprintf.c

HEADERS = ft_printf.h put_padding.h color.h base_utils.h

SRC = $(addprefix $(SRC_DIR)/, $(SRC_RAW))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_RAW:.c=.o))
INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(HEADERS))

CFLAGS = -g3 -O3 -Wall -I $(INCLUDES_DIR)

RED := "\033[0;31m"
GREEN := "\033[0;32m"
CYAN := "\033[0;36m"
YELLOW := "\033[0;33m"
RESET :="\033[0m"

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) $(MAKEFILE)
	@mkdir -p $(OBJ_DIR)
	@gcc -c $< -o $@ $(CFLAGS) 

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo ${GREEN}"[INFO] Created libftprintf.a successfully!"${RESET}

test: all
	@gcc -c $(CFLAGS) $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o
	@gcc $(CFLAGS) $(OBJ) $(OBJ_DIR)/main.o -o ft_printf
	@echo ${GREEN}"[INFO] Compiled 'ft_printf' executable with success!"${RESET}

double: all
	@gcc -c $(CFLAGS) $(SRC_DIR)/main_f.c -o $(OBJ_DIR)/main_f.o
	@gcc $(CFLAGS) $(OBJ) $(OBJ_DIR)/main_f.o -o ft_printf
	@echo ${GREEN}"[INFO] Compiled 'ft_printf' executable with success!"${RESET}

clean: 
	@rm -f $(OBJ)
	@rm -Rf $(OBJ_DIR)
	@echo ${CYAN}"[INFO] Removed [$(OBJ)] with success!"${RESET}
	@echo ${CYAN}"[INFO] Removed [$(OBJ_DIR)] with success!"${RESET}

fclean: clean
	@rm -Rf $(NAME)
	@rm -Rf ft_printf
	@echo ${CYAN}"[INFO] Removed everything because SKIBIDI PA PA"${RESET}

re: fclean all

.PHONY: fclean all clean libft
