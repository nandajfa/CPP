/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:33:58 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/02 21:28:40 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal") {
	std::cout << GRN << "Default constructor AAnimal called." << RESET << std::endl;
	return;
}

AAnimal::AAnimal(AAnimal const& copy){
	std::cout << GRN << "Copy constructor AAnimal called." << RESET << std::endl;
	*this = copy;
}

AAnimal::~AAnimal(void){
	std::cout << GRN << "Destructor AAnimal called." << RESET << std::endl;
	return;
}

AAnimal& AAnimal::operator=(AAnimal const & src){
	if (this != &src)
		this->_type = src.getType();
	std::cout << GRN << "Copy assignment AAnimal operator called." << RESET << std::endl;
	return (*this);
}

std::string	AAnimal::getType(void) const{
	return(this->_type);
}

void	AAnimal::setType(std::string type){
	this->_type = type;
}

void	AAnimal::makeSound(void) const{
	std::cout << GRN << "This " << this->_type << " does not make sounds."  << RESET << std::endl;
}
