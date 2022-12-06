# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpradene <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 12:33:43 by lpradene          #+#    #+#              #
#    Updated: 2022/11/23 11:13:17 by lpradene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c \
		ft_puthex.c \
		ft_putnbr.c \
		ft_putunbr.c \
		ft_putstr.c \
		ft_putptr.c

OBJS	= ${SRCS:.c=.o}

CC	= cc

FLAGS	= -Wall -Wextra -Werror

NAME	= libftprintf.a

${NAME}:
	${CC} ${FLAGS} ${SRCS} -c
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: re fclean clean all
