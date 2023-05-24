/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:08:53 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/23 21:42:12 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void) : _nbContacts(0), _index(0) {
	return ;
}
PhoneBook::~PhoneBook(void) {
	return ;
}

void	PhoneBook::add(void)
{
	std::string	info[5];

	std::cout << CYAN << "Add the following information."
		<< " Fields cannot be empty or contain only spaces."<< RESET << std::endl;
	info[0] = PhoneBook::_getInfo("Enter the first name:");
	info[1] = PhoneBook::_getInfo("Enter the last name:");
	info[2] = PhoneBook::_getInfo("Enter the nickname:");
	while (info[3].empty())
	{
		if (std::cin.eof())
           exit(0);
		std::cout << "Enter phone number:" << std::endl;
		std::getline(std::cin, info[3]);
		if (PhoneBook::_validPhone(info[3]) == false)
			info[3] = "";
	}
	info[4] = PhoneBook::_getInfo("Enter darkest secret:");
	PhoneBook::_addContact(info);
}

void	PhoneBook::_addContact(std::string info[5])
{
	Contact	contact;

	contact.setFirstName(info[0]);
	contact.setLastName(info[1]);
	contact.setNickname(info[2]);
	contact.setPhone(info[3]);
	contact.setSecret(info[4]);
	if (this->_nbContacts < 8){
		this->_contacts[this->_index] = contact;
		this->_index = (this->_index + 1) % 8;
		this->_nbContacts++;	
	} else {
		std::cout << CYAN << "Limit of 8 contacts, the oldest contact will be replaced." << RESET << std::endl;
        this->_contacts[this->_index] = contact;
        this->_index = (this->_index + 1) % 8;
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
	std::cout << GREY << "================Contact list================" << RESET << std::endl;
    std::cout << std::setw(10) << std::right << "Index" << "|"
    	<< std::setw(10) << std::right << "First name" << "|"
		<< std::setw(10) << std::right << "Last name" << "|"
    	<< std::setw(10) << std::right << "Nickname" << "|" << std::endl;
	i = 0;
	while (i < this->_nbContacts){
		PhoneBook::_printTable(i);
		i++;
	}
	std::cout << GREY << "============================================" << RESET << std::endl;
	PhoneBook::_getIndex();
}

void	PhoneBook::_printTable(int i)
{
	std::cout << std::setw(10) << std::right << i << "|"
		<< std::setw(10) << std::right << PhoneBook::_truncateStr(this->_contacts[i].getFirstName()) << "|"
		<< std::setw(10) << std::right << PhoneBook::_truncateStr(this->_contacts[i].getLastName()) << "|"
		<< std::setw(10) << std::right << PhoneBook::_truncateStr(this->_contacts[i].getNickname()) << "|";
	std::cout << std::endl;
}

void	PhoneBook::_getIndex()
{
	int index = -1;
	std::string	buffer;

	std::cout << std::endl;
	while (index < 0 || index > this->_nbContacts || buffer.empty()){
		std::cout << "Enter the index of the contact to display:" << std::endl;
		std::getline(std::cin, buffer);
		if (std::cin.eof())
           exit(0);
		bool isInvalidInput = false;
		for (std::size_t i = 0; i < buffer.size(); ++i){
            if (!std::isdigit(buffer[i]))
                isInvalidInput = true;
        }
		std::istringstream ss(buffer);
		if (!(ss >> index) || !ss.eof() || isInvalidInput || index < 0 || index >= this->_nbContacts){
			std::cout << RED << "Invalid index." << RESET << std::endl;
			index = -1;
			continue;
		}
		break ;
	}
	printContact(index);
	std::cin.clear();
}

void	PhoneBook::printContact(int index)
{
	std::cout << std::endl;
	std::cout << "First name: " << this->_contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << this->_contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->_contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << this->_contacts[index].getPhone() << std::endl;
	std::cout << "Darkest secret: " << this->_contacts[index].getSecret() << std::endl << std::endl;
}
