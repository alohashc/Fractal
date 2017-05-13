# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alohashc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/06 10:48:43 by alohashc          #+#    #+#              #
#    Updated: 2017/03/27 12:54:49 by alohashc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = ./draw_functions.c \
	  ./burningship.c \
	  ./julia.c \
	  ./carpet.c \
	  ./main.c \
	  ./events.c \
	  ./math_function.c \
	  ./mandelbrot.c \
	  ./reset.c \
	  ./newton.c \

O_FILE = $(SRC:.c=.o)

INC = ./

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(O_FILE)
	make -C ./libft/
	gcc -o $(NAME) $(O_FILE) -L ./libft/ -lft -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	gcc $(FLAGS) -I $(INC) -c $< 

clean:
	make clean -C ./libft/
	rm -rf $(O_FILE)

fclean: clean
	make fclean -C ./libft/
	rm -rf $(NAME)

re: clean all
