# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 00:34:13 by fstitou           #+#    #+#              #
#    Updated: 2023/01/16 00:34:18 by fstitou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= stack
CC		= c++ -std=c++98 
FLAGS	= -Wall -Werror -Wextra
SRCS 	= main.cpp
			
$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all