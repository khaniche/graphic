# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khaniche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 22:16:47 by khaniche          #+#    #+#              #
#    Updated: 2019/06/17 22:16:48 by khaniche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_F = src
SRC_NAME = main.c draw.c init.c hooks.c func.c burn.c burnbuf.c\
cub_mand.c julia.c mandelbrot.c man_hor.c man_4.c cubbaf.c init2.c\
switch.c

OBJ_F = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = clang
CFLAGS = -O2 

FLAGS = -I incl -I libft/incl

LDFLAGS = -L libft
LDLIBS = -lft -lm -lmlx -framework OpenGL -framework AppKit

SRC = $(addprefix $(SRC_F)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_F)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "Compilation of Fractol:	\033[1;32mOK\033[m"

$(OBJ_F)/%.o: $(SRC_F)/%.c
	@mkdir $(OBJ_F) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< $(FLAGS) -o $@

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_F) 2> /dev/null || true
	@echo "Fractol: Removing Obj"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "Fractol : Removing Fractol"

re: fclean all

.PHONY: all clean fclean re
