# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aerrazik <aerrazik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 17:16:10 by aerrazik          #+#    #+#              #
#    Updated: 2022/07/23 01:47:51 by aerrazik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
GCF = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit #-g -fsanitize=address
NAME = fdf
BO = fdf_bonus
SRC = main.c errors.c ft_atoi.c ft_split.c get_next_line.c tools.c \
		get_next_line_utils.c x.c y.c

OBJS = ${SRC:.c=.o}

all : $(NAME)

$(NAME) : $(SRC)
		CC $(GCF) $(SRC) -o $(NAME)

clean :
	rm -rf ${OBJS}
	
fclean : clean
	rm -rf ${NAME}

re : fclean all
