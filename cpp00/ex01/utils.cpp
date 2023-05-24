/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:44:54 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/23 21:41:33 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string	PhoneBook::_truncateStr(std::string contact)
{
	if (contact.length() > 9){
		contact = contact.substr(0, 9) + ".";
	}
	return (contact);
}

bool	PhoneBook::_validPhone(std::string phone)
{
	int i = 0;

	while (phone[i])
	{
		if (std::cin.eof())
           exit(0);
		if (!std::isdigit(phone[i])){
			std::cout << RED << "Phone number must only contain numbers" << RESET << std::endl;
			return (false);
		}
		i++;
	}
	if (phone.size() < 3 || phone.size() > 14){
		std::cout << RED << "The size of the phone number must be between 3 and 14." << RESET << std::endl;
		return (false);
	}
	return (true);
}

std::string	PhoneBook::_getInfo(std::string info)
{
	std::string	input;

	while (input.empty())
	{
		if (std::cin.eof())
           exit(0);
		std::cout << info << std::endl;
		std::getline(std::cin, input);
		if (_verifySpaces(input))
			input = "";
	}
	return (input);
}

bool PhoneBook::_verifySpaces(const std::string& str) {
    return str.find_first_not_of(' ') == std::string::npos;
}
