/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:01:25 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/23 01:22:25 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	std::cout << BBLU << "=====Welcome to my Awesome PhoneBook=====" << RESET << std::endl;
	while (1)
	{
		std::cout << BOLD_WHITE << "Please, enter one of the options:" << RESET << std::endl;
		std::cout << BOLD_WHITE << "ADD, SEARCH or EXIT" << RESET << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD" || input == "add")
			phonebook.add();
		else if (input == "SEARCH" || input == "search")
			phonebook.searchContact();
		else if (input == "EXIT" || input == "exit" || std::cin.eof())
			exit(0);
		else
			std::cout << RED << "Invalid command." << RESET << std::endl;
	}
	return (0);
}
