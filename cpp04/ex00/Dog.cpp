/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:33:58 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/29 00:40:30 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	this->setType("Dog");
	std::cout << BLU << "Default constructor Dog called." << RESET << std::endl;
	return;
}

Dog::Dog(Dog const& copy) : Animal() {
	std::cout << BLU << "Copy constructor Dog called." << RESET << std::endl;
	*this = copy;
}

Dog::~Dog(void){
	std::cout << BLU << "Destructor Dog called." << RESET << std::endl;
	return;
}

Dog& Dog::operator=(Dog const & src){
	if (this != &src)
		this->setType(src.getType());
	std::cout << BLU << "Copy assignment Dog operator called." << RESET << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const{
	std::cout << BLU << "The " << this->_type << " barks"<< RESET << std::endl;
}
