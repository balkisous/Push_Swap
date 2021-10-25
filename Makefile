# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42@student.42.fr <user42>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 07:17:52 by bben-yaa          #+#    #+#              #
#    Updated: 2021/10/18 15:42:53 by user42@stud      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	=./srcs/fonction_psw/ft_fonction.c \
		./srcs/fonction_psw/ft_fonction_psw.c \
		./srcs/fonction_psw/ft_print.c \
		./srcs/parsing/ft_parsing.c \
		./srcs/parsing/ft_free_and_check.c \
		./srcs/parsing/ft_parsing2.c \
		./srcs/parsing/ft_parsing3.c \
		./srcs/main/ft_init_stack.c \
		./srcs/algorithm/ft_algorithm.c \
		./srcs/algorithm/ft_sort_place.c \
		./srcs/algorithm/ft_reference.c \
		./srcs/algorithm/ft_reference2.c \
		./srcs/algorithm/ft_absolute.c \
		./srcs/algorithm/ft_insort.c \
		./srcs/algorithm/algo_3.c

PUSH_SWAP	= push_swap

OBJ		= $(SRCS:.c=.o)
RM		= rm -rf
CC		= clang
FLAGS	= -Wall -Werror -Wextra

%.o : %.c
	$(CC) -c $(CFLAGS) $(FLAGS) -o $@ $<
				
${PUSH_SWAP}:	${OBJ}
			$(CC) ${FLAGS} ${OBJ} -o ${PUSH_SWAP}

all		: ${PUSH_SWAP}

clean	:
				${RM} ${OBJ}

fclean	:	clean
				${RM} ${PUSH_SWAP}

re		:	fclean all

.PHONY : all clean fclean re
