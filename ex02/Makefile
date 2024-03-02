# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 19:06:48 by fabou-za          #+#    #+#              #
#    Updated: 2023/05/23 14:31:20 by fabou-za         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe
CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++

SRC_NAME = PmergeMe.cpp main.cpp

OBJ_NAME = $(SRC_NAME:%.cpp=%.o)
HEADERS = PmergeMe.hpp

all: $(NAME)

$(NAME): $(OBJ_NAME)
	$(CC) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f *.o
fclean: clean 
	rm -rf $(NAME)
re: fclean all
