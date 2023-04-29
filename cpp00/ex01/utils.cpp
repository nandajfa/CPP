/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:44:54 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 15:47:16 by jefernan         ###   ########.fr       */
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
		if (!std::isdigit(phone[i]))
		{
			std::cout << RED << "Phone number must only contain numbers" << RESET << std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}
