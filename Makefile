# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpons <mpons@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 14:01:49 by mpons             #+#    #+#              #
#    Updated: 2022/03/18 10:58:56 by mpons            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

CC			= gcc
# -pthread dans CFLAGS?
CFLAGS		= -g -Wall -Wextra -Werror -fsanitize=address

OBJS		= ${SRC:.c=.o}

RM			= rm -f

SRC			= ./main.c\
			  ./check.c\
			  ./utils.c\
			  ./pthread_and_mutex.c\
			  ./philo_life.c\
			  ./philo_check.c\

all: $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:	all clean fclean re bonus
