/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:08:50 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 15:47:30 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream> /* std::cout */
#include <iomanip> /* std::setw */
#include <stdlib.h> /*exit*/

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
	bool		_validPhone(std::string phone);
	std::string	_truncateStr(std::string contact);
public:
	PhoneBook( void ); /*constructor*/
	~PhoneBook( void ); /*destructor*/

	void		getInfo(void);
	void		addContact(std::string info[5]);
	void		searchContact();
	void		printContact(void);
};

#endif
