/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:08:50 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/23 21:20:26 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream> /* std::cout */
#include <iomanip> /* std::setw */
#include <stdlib.h> /*exit*/
#include <sstream> 

/* ANSI COLOR CODES */
#define RESET "\033[0m"
#define RED "\033[31m"
#define BBLU "\e[1;34m"
#define PURPLE "\e[0;35m"
#define GRN "\e[0;32m"
#define CYAN "\033[36;1m"
#define BOLD_WHITE "\e[1;37m"
#define GREY	"\033[38;5;244m"

class PhoneBook {

private:
	Contact	_contacts[8];
	int		_nbContacts;
	int		_index;

	void		_printTable(int i);
	void		_addContact(std::string info[5]);
	void		_getIndex();
	bool		_validPhone(std::string phone);
	bool 		_verifySpaces(const std::string& str);
	std::string	_truncateStr(std::string contact);
	std::string	_getInfo(std::string info);
public:
	PhoneBook( void ); /*constructor*/
	~PhoneBook( void ); /*destructor*/
	
	void		add(void);
	void		searchContact();
	void		printContact(int index);
};

#endif
