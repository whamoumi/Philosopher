# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 13:18:14 by whamoumi          #+#    #+#              #
#    Updated: 2021/12/18 16:59:03 by whamoumi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philosopher	
SRCS		=	philosopher.c philosopher_eat.c philosopher_parsing.c \
				philosopher_routine.c philosopher_time.c \
				philosopher_utils.c

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

all:			${NAME}

$(NAME):		${OBJS}
				${CC} -o ${NAME} ${OBJS} ${CFLAGS}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all
