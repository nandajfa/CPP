# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 15:57:33 by jefernan          #+#    #+#              #
#    Updated: 2023/04/12 16:38:31 by jefernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf
SRC		= megaphone.cpp
OBJ		= $(SRC:.cpp=.o)

all:	$(NAME)

.cpp.o:
		@$(CC) $(FLAGS) -c $< -o $@
		@echo "\e[0;35m Successfully compiled! \e[0m"

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(FLAGS) -o $(NAME)

clean:
		@$(RM) $(OBJ)
		@echo "\e[0;36m Objects removed! \e[0m"

fclean: clean	
		@$(RM) $(NAME)
		@echo "\e[0;36m Program has been cleaned! \e[0m"

re: 	fclean all

.PHONY: all clean fclean re