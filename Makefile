# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 17:24:39 by anloisea          #+#    #+#              #
#    Updated: 2022/10/03 17:25:06 by anloisea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
SRCS		= 	./srcs/main.c \
				./srcs/get_map.c \
				./srcs/free_map.c
				
OBJS		=	${SRCS:.c=.o}

HDR			=	so_long.h
CFLAGS		= 	-Wall -Wextra -Werror
CC			= 	gcc
MINILIBX	= -L /usr/local/lib/ -lmlx -framework Opengl -framework Appkit
INCLUDE		= -I /usr/local/include/			
LIB			= ./libft/libft.a


all:		${LIB} ${NAME}

${LIB}:
			@make all -sC ./libft

${NAME}:	${LIB}	${OBJS}
			${CC} ${CFLAGS} ${INCLUDE} ${OBJS} ${MINILIBX} -L./libft -lft -o ${NAME}
			@echo "\033[92mso_long compiled successfully\033[0m"

clean:
			@make clean -sC ./libft
			rm -rf ${OBJS}

fclean:		clean
			@make fclean -sC ./libft
			rm -rf ${NAME} ${LIB}

re:			fclean all

.PHONY:		all clean fclean re
