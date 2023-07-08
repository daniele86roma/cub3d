# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 10:46:16 by dfiliagg          #+#    #+#              #
#    Updated: 2023/05/30 10:27:42 by adi-fort         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d
FLAGS	=  -Wall -Wextra -Werror
CC		= gcc ${FLAGS}
RM		= rm -f
SRC		= cub3d.c ${GNL}
GNL		= get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJ		= ${SRC:.c=.o}
LFT		= libft/libft.a
MLX		= minilibx-linux/libmlx.a

all: ${NAME}

${LFT}:
		make -C libft
${MLX}:
		make -C minilibx-linux
.o:.c
	${CC} ${OBJ} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ} ${LFT} ${MLX} 
	${CC} ${OBJ} ${LFT} ${MLX} -o ${NAME}

clean:
	${RM} ${OBJ}
	make clean -C libft
	make clean -C minilibx-linux

fclean: clean
	${RM} ${NAME}
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re