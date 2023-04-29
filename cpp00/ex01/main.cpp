/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:01:25 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 15:48:03 by jefernan         ###   ########.fr       */
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
		if (input == "ADD")
			phonebook.getInfo();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else if (input == "EXIT")
			exit(0);
		else
			std::cout << RED << "Invalid command." << RESET << std::endl;
	}
	return (0);
}
