# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoine <antoine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 17:24:39 by anloisea          #+#    #+#              #
#    Updated: 2022/10/06 15:51:24 by antoine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
SRCS		= 	./srcs/mlx_test.c \
				./srcs/get_map.c \
				./srcs/free_map.c \
				./srcs/check_map.c
				
OBJS		=	${SRCS:.c=.o}

HDR			=	so_long.h
//CFLAGS		= 	-Wall -Wextra -Werror
CC			= 	gcc
//MINILIBX	= -L /usr/local/lib/ -lmlx -framework Opengl -framework Appkit
MLX_LINUX 	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
INCLUDE		= -I /usr/local/include/			
LIB			= ./libft/libft.a

%.o: %.c
	$(CC) ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:		${LIB} ${NAME}

${LIB}:
			@make all -sC ./libft

${NAME}:	${LIB}	${OBJS}
			${CC} ${CFLAGS} ${INCLUDE} ${OBJS} ${MLX_LINUX} -L./libft -lft -o ${NAME}
			@echo "\033[92mso_long compiled successfully\033[0m"

clean:
			@make clean -sC ./libft
			rm -rf ${OBJS}

fclean:		clean
			@make fclean -sC ./libft
			rm -rf ${NAME} ${LIB}

re:			fclean all

.PHONY:		all clean fclean re
