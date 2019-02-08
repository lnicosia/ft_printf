# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 15:56:21 by lnicosia          #+#    #+#              #
#    Updated: 2019/02/08 17:48:18 by lnicosia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

MAKEFILE = Makefile

SRC_DIR = src
OBJ_DIR = obj
INCLUDES_DIR = includes
BIN_DIR = .

SRC_RAW = pf_putchar.c pf_putstr.c main.c ft_printf.c pf_putnbr.c pf_putunbr.c \
		  pf_putaddr.c pf_putnbr_base.c pf_invalid.c pf_putpercent.c \
		  pf_putlong_base.c parse_options.c pf_atoi.c

HEADERS = ft_printf.h

SRC = $(addprefix $(SRC_DIR)/, $(SRC_RAW))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_RAW:.c=.o))
INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(HEADERS))

CFLAGS = -g3 -O3 -Wall -I $(INCLUDES_DIR) -fsanitize=address \

RED := "\033[0;31m"
GREEN := "\033[0;32m"
CYAN := "\033[0;36m"
RESET :="\033[0m"

all:
	@make $(BIN_DIR)/$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) $(MAKEFILE)
	@mkdir -p $(OBJ_DIR)
	@gcc -c $< -o $@ $(CFLAGS) 

$(BIN_DIR)/$(NAME): $(OBJ)
	@gcc $(CFLAGS) $(OBJ) -o $(NAME)
	@echo ${GREEN}"[INFO] Compiled '$(NAME)' executable with success!"${RESET}

clean: 
	@rm -f $(OBJ)
	@rm -Rf $(OBJ_DIR)
	@echo ${CYAN}"[INFO] Removed [$(OBJ)] with success!"${RESET}
	@echo ${CYAN}"[INFO] Removed [$(OBJ_DIR)] with success!"${RESET}

fclean: clean
	@rm -Rf $(NAME)
	@echo ${CYAN}"[INFO] Removed everything because SKIBIDI PA PA"${RESET}

re: fclean all

.PHONY: fclean all clean libft
