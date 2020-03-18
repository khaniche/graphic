# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khaniche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 19:51:09 by khaniche          #+#    #+#              #
#    Updated: 2019/04/18 19:51:14 by khaniche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit 

CC = clang

CFLAGS = -Wall -Werror -Wextra -I $(HEADERS) -o $(NAME)

SRC = main.c ft_reader.c map.c ft_backtracker.c

LIBFT_DIR = libft

LIBS = libft/libft.a

OBJ = $(SRC:.c=.o)

HEADERS = .

all: $(NAME)

$(LIBS):
	make -C $(LIBFT_DIR)

$(NAME): $(SRC) $(LIBS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIBS)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
