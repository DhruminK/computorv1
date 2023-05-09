# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 16:19:24 by dkhatri           #+#    #+#              #
#    Updated: 2023/05/09 18:54:15 by dkhatri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = computorv1

PARSER = ft_parser.c ft_parse_helper.c
SOLVER = ft_solve_eqn.c helper_func.c
MATH_FUNC = math_helper_func.c ft_sqrt.c
MAIN = computorv1.c

SRC = $(PARSER) $(SOLVER) $(MATH_FUNC) $(MAIN)
OBJ = $(SRC:.c=.o)

INC = computor.h
INCLUDES = -I include/

SRC_PATH = src/
INC_PATH = include/
OBJ_PATH = obj/

OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
SRCS = $(addprefix $(SRC_PATH), $(SRC))
INCS = $(addprefix $(INC_PATH), $(INC))

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCS)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(INCLUDES) $(CFLAGS) -o $@ -c $<
	@echo "\033[1m$(NAME)\033[0m \
		: Compiling $< to $@ \033[1;32m[OK]\033[0m"

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(INCLUDES) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1m$(NAME)\033[0m \
		: Compiling $@ \033[1;32m[OK]\033[0m"

clean:
	@/bin/rm -f $(OBJS)
	@echo "\033[1m$(NAME)\033[0m \
		: Cleaned $(OBJ_PATH) \033[1;32m[OK]\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[1m$(NAME)\033[0m \
		: binary deleted \033[1;32m[OK]\033[0m"

re: fclean all

.PHONY: all clean fclean re
