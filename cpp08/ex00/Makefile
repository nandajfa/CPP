# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 22:09:47 by jefernan          #+#    #+#              #
#    Updated: 2023/06/20 22:19:47 by jefernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= easyfind
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

SRC		= main.cpp
		
HEADER	=  easyfind.hpp

OBJ_DIR	= ./obj
OBJ		= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all:	$(NAME)

$(NAME): $(OBJ_DIR)  $(OBJ)
		@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
		@echo "\e[0;35m Successfully compiled! \e[0m"

$(OBJ_DIR)/%.o:	%.cpp $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@ 
	
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
		@$(RM) $(OBJ_DIR)
		@echo "\e[0;36m Objects removed! \e[0m"

fclean: clean
		@$(RM) $(NAME)
		@echo "\e[0;36m Program has been cleaned! \e[0m"

re: 	fclean all

.PHONY: all clean fclean re
