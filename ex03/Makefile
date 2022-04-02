# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 21:26:04 by msousa            #+#    #+#              #
#    Updated: 2022/04/02 20:51:52 by msousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror -std=c++98
CC			= clang++
RM			= rm -f
OBJ			= ${SRC:%.cpp=obj/%.o}
SRC			= main.cpp Fixed.cpp Point.cpp bsp.cpp
INC			= Fixed.hpp Point.hpp

NAME		= bsp

${NAME}:	${OBJ}
					${CC} ${CFLAGS} ${OBJ} -o $@

obj/%.o:%.cpp ${INC}
					@mkdir -p $(dir $@)
					${CC} ${CFLAGS} -c $< -o $@

all:			${NAME}

test:			${NAME}
					-./${NAME}

clean:
					${RM} -rf obj

fclean:		clean
					${RM} ${NAME}

re: 			fclean all

.PHONY : 	all clean fclean re
