# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoine <antoine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 17:24:39 by anloisea          #+#    #+#              #
#    Updated: 2022/10/22 14:08:25 by antoine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
SRCS		= 	./srcs/main.c \
				./srcs/get_map.c \
				./srcs/free_data.c \
				./srcs/check_map.c \
				./srcs/error.c \
				./srcs/init_data.c \
				./srcs/utils.c \
				./srcs/is_playable.c \
				./srcs/print_tiles.c \
				./srcs/init_mlx.c
				
OBJS		=	${SRCS:.c=.o}

HDR			=	so_long.h
CFLAGS		= 	-Wall -Wextra -Werror
CC			= 	gcc
//MLX	= -L /usr/local/lib/ -lmlx -framework Opengl -framework Appkit
MLX 	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
INCLUDE		= -I /usr/local/include/			
LIB			= ./libft/libft.a

%.o: %.c
	$(CC) ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:		${LIB} ${NAME}

${LIB}:
			@make all -sC ./libft

${NAME}:	${LIB}	${OBJS}
			${CC} ${CFLAGS} ${INCLUDE} ${OBJS} ${MLX} -L./libft -lft -o ${NAME}
			@echo "\033[92mso_long compiled successfully\033[0m"

clean:
			@make clean -sC ./libft
			rm -rf ${OBJS}

fclean:		clean
			@make fclean -sC ./libft
			rm -rf ${NAME} ${LIB}

re:			fclean all

.PHONY:		all clean fclean re
