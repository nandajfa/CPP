/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:33:58 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/29 00:40:30 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << CYN << "Default constructor WrongCat called." << RESET << std::endl;
	return;
}

WrongCat::WrongCat(WrongCat const& copy) : WrongAnimal() {
	std::cout << CYN << "Copy constructor WrongCat called." << RESET << std::endl;
	*this = copy;
}

WrongCat::~WrongCat(void){
	std::cout << CYN << "Destructor WrongCat called." << RESET << std::endl;
	return;
}

WrongCat& WrongCat::operator=(WrongCat const & src){
	if (this != &src)
		this->_type = src.getType();
	std::cout << CYN << "Copy assignment WrongCat operator called." << RESET << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const{
	std::cout << CYN << "The " << this->_type << " miaaWs" << RESET << std::endl;
}
