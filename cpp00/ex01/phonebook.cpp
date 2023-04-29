/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:08:53 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 15:47:45 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void) : _nbContacts(0), _index(0) {
	return ;
}
PhoneBook::~PhoneBook(void) {
	return ;
}

void	PhoneBook::getInfo(void)
{
	std::string	info[5];

	std::cout << "Enter the first name:" << std::endl;
	std::getline(std::cin, info[0]);
	std::cout << "Enter the last name:" << std::endl;
	std::getline(std::cin, info[1]);
	std::cout << "Enter the nickname:" << std::endl;
	std::getline(std::cin, info[2]);
	std::cout << "Enter phone number:" << std::endl;
	std::getline(std::cin, info[3]);
	while (PhoneBook::_validPhone(info[3]) == false)
	{
		std::cout << "Enter phone number:" << std::endl;
		std::getline(std::cin, info[3]);
	}
	std::cout << "Enter darkest secret:" << std::endl;
	std::getline(std::cin, info[4]);
	if (info[0].empty() || info[1].empty() || info[2].empty() || info[3].empty() || info[4].empty())
	{
		std::cout << RED << "Not added. The contact can’t have empty fields." << RESET << std::endl;
		return ;
	}
	PhoneBook::addContact(info);
}

void	PhoneBook::addContact(std::string info[5])
{
	Contact	contact;

	if (this->_nbContacts < 8){
		contact.setFirstName(info[0]);
		contact.setLastName(info[1]);
		contact.setNickname(info[2]);
		contact.setPhone(info[3]);
		contact.setSecret(info[4]);
		this->_contacts[this->_index] = contact;
		this->_index = (this->_index + 1) % 8;
		this->_nbContacts++;
	} else {
		std::cout << CYAN << "Limit of 8 contacts, first contact will be replaced" << RESET << std::endl;
        this->_contacts[0] = contact;
	}
	std::cout << GRN << "Contact has been added" << RESET << std::endl;
}

void	PhoneBook::searchContact()
{
	int	i;

	if (this->_nbContacts == 0){
		std::cout << CYAN << "No contacts found." << RESET << std::endl;
		return;
	}
	std::cout << std::endl;
	std::cout << GREY << "     ----------Contact list----------" << RESET << std::endl;
    std::cout << std::setw(10) << std::right << "Index" << "|"
    	<< std::setw(10) << std::right << "First name" << "|"
		<< std::setw(10) << std::right << "Last name" << "|"
    	<< std::setw(10) << std::right << "Nickname" << "|" << std::endl;
	i = 0;
	while (i < this->_nbContacts){
		_printTable(i);
		i++;
	}
	printContact();
}

void	PhoneBook::_printTable(int i)
{
	std::cout << std::setw(10) << std::right << i << "|"
		<< std::setw(10) << std::right << PhoneBook::_truncateStr(this->_contacts[i].getFirstName()) << "|"
		<< std::setw(10) << std::right << PhoneBook::_truncateStr(this->_contacts[i].getLastName()) << "|"
		<< std::setw(10) << std::right << PhoneBook::_truncateStr(this->_contacts[i].getNickname()) << "|";
	std::cout << std::endl;
}

void	PhoneBook::printContact()
{
	int index;

	std::cout << std::endl;
	std::cout << "Enter the index of the contact to display: ";
	std::cin >> index;
	if (!std::cin || index < 0 || index >= this->_nbContacts){
    	std::cout << RED << "Invalid index." << RESET << std::endl;
		std::cin.clear();
		std::cin.ignore(__INT_MAX__, '\n');
	}
	else {
		std::cout << std::endl;
		std::cout << "First name: " << this->_contacts[index].getFirstName() << std::endl;
    	std::cout << "Last name: " << this->_contacts[index].getLastName() << std::endl;
    	std::cout << "Nickname: " << this->_contacts[index].getNickname() << std::endl;
    	std::cout << "Phone number: " << this->_contacts[index].getPhone() << std::endl;
    	std::cout << "Darkest secret: " << this->_contacts[index].getSecret() << std::endl << std::endl;
		std::cin.clear();
		std::cin.ignore(__INT_MAX__, '\n');
	}
}
