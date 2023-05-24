# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 18:11:23 by jefernan          #+#    #+#              #
#    Updated: 2023/04/29 20:47:58 by jefernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= phonebook
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf
HEADER	= contact.hpp phonebook.hpp
SRC		= main.cpp phonebook.cpp contact.cpp utils.cpp
OBJ		= $(SRC:.cpp=.o)

all:	$(NAME)

.cpp.o: $(SRC)/%.cpp $(HEADER)
		@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
		@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
		@echo "\e[0;35m Successfully compiled! \e[0m"

clean:
		@$(RM) $(OBJ)
		@echo "\e[0;36m Objects removed! \e[0m"

fclean: clean	
		@$(RM) $(NAME)
		@echo "\e[0;36m Program has been cleaned! \e[0m"

re: 	fclean all

.PHONY: all clean fclean re
