# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 00:34:06 by fstitou           #+#    #+#              #
#    Updated: 2023/02/20 08:56:51 by fstitou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= map
CC		= c++ -std=c++11 -fsanitize=address -g3	
FLAGS	= -Wall -Werror -Wextra
SRCS 	= main.cpp
			
$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)
	rm -rf *.dSYM
re: fclean all