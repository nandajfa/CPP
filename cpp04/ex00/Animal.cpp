/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:33:58 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/02 21:31:10 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal") {
	std::cout << GRN << "Default constructor Animal called." << RESET << std::endl;
	return;
}
Animal::Animal(Animal const& copy){
	std::cout << GRN << "Copy constructor Animal called." << RESET << std::endl;
	*this = copy;
}
Animal::~Animal(void){
	std::cout << GRN << "Destructor Animal called." << RESET << std::endl;
	return;
}

Animal& Animal::operator=(Animal const & src){
	if (this != &src)
		this->_type = src.getType();
	std::cout << GRN << "Copy assignment Animal operator called." << RESET << std::endl;
	return (*this);
}

std::string	Animal::getType(void) const{
	return(this->_type);
}

void	Animal::setType(std::string type){
	this->_type = type;
}

void	Animal::makeSound(void) const{
	std::cout << GRN << "This " << this->_type << " does not make sounds."  << RESET << std::endl;
}
