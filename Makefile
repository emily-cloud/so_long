# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hai <hai@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 10:59:47 by hai               #+#    #+#              #
#    Updated: 2024/05/19 11:10:28 by hai              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

CPPFLAGS = -Ilibs/libft/headers -Ilibs/mlx-linux

LDFLAGS = -Llibs/mlx-linux -Llibs/libft

MLXFLAG = -lft -lmlx -lXext -lX11

SRCS = check_map1.c check_map2.c check_map3.c \
		create_display.c get_map_data1.c \
		get_map_data2.c main.c move_down.c move_left.c \
		move_right.c move_up.c utils.c input_process.c

all: $(NAME)

$(NAME): $(SRCS:.c=.o)
		make -C ./libs/libft
		$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(SRCS:.c=.o) $(MLXFLAG) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^ -o $@

clean:
		make clean -C ./libs/libft
		rm -rf $(SRCS:.c=.o)

fclean: clean
		rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re


