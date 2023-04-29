# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 01:26:46 by jefernan          #+#    #+#              #
#    Updated: 2023/04/29 15:58:59 by jefernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= unnecessary_violence
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

SRC		= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
HEADER	= Weapon.hpp HumanA.hpp HumanB.hpp

OBJ_DIR	= ./obj
OBJ		= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all:	$(NAME)

$(NAME): $(OBJ_DIR)  $(OBJ)
		@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
		@echo "\e[0;35m Successfully compiled! \e[0m"

$(OBJ_DIR)/%.o:	%.cpp $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

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
