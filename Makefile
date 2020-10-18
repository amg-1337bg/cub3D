# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/02 10:12:28 by bamghoug          #+#    #+#              #
#    Updated: 2020/10/17 16:26:56 by bamghoug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBFT = libft.a

FLAGS = -Wall -Wextra -Wall

SRC = cub3d_utils.c get_next_line.c get_next_line_utils.c initials.c get_text.c \
moves.c sprites.c sprites1.c save_arg.c intial1.c cal_interc.c get_config.c \
angle_text.c check_input.c check_input1.c input_scan.c input_scan1.c \
input_scan2.c input_scan3.c positions.c main.c

all : $(NAME)

$(NAME) :
	make -C ./libft
	gcc $(FLAGS) $(SRC) -g -fsanitize=address libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	cd libft && make clean

fclean : clean
	cd libft && make fclean
	rm $(NAME)

re : fclean all

.PHONY: all clean fclean re
