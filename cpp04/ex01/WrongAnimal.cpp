/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:33:58 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/29 00:40:30 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
	std::cout << MAG << "Default constructor WrongAnimal called." << RESET << std::endl;
	return;
}

WrongAnimal::WrongAnimal(WrongAnimal const& copy) {
	std::cout << MAG << "Copy constructor WrongAnimal called." << RESET << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << MAG << "Destructor WrongAnimal called." << RESET << std::endl;
	return;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const & src){
	if (this != &src)
		this->_type = src.getType();
	std::cout << MAG << "Copy assignment WrongAnimal operator called." << RESET << std::endl;
	return (*this);
}

std::string	WrongAnimal::getType(void) const{
	return(this->_type);
}

void	WrongAnimal::makeSound(void) const{
	std::cout << MAG << "The " << this->_type << " make some sound." << RESET << std::endl;
}
