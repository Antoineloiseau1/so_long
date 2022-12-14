# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 17:24:39 by anloisea          #+#    #+#              #
#    Updated: 2022/10/24 15:47:07 by anloisea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
SRCS		= 	./srcs/main.c \
				./srcs/get_map.c \
				./srcs/free.c \
				./srcs/check_map.c \
				./srcs/exit.c \
				./srcs/init.c \
				./srcs/utils.c \
				./srcs/is_playable.c \
				./srcs/print_map.c \
				./srcs/game.c
				
OBJS		=	${SRCS:.c=.o}

HDR			=	so_long.h
CFLAGS		= 	-g -Wall -Wextra -Werror
CC			= 	gcc
MLX			= -L /usr/local/lib/ -lmlx -framework Opengl -framework Appkit
//MLX 		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
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
