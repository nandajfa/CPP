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

Dog::Dog(void) : AAnimal() {
	this->setType("Dog");
	this->_brain = new Brain();
	std::cout << BLU << "Default constructor Dog called." << RESET << std::endl;
	return;
}

Dog::Dog(Dog const& copy) : AAnimal() {
	std::cout << BLU << "Copy constructor Dog called." << RESET << std::endl;
	this->_brain = new Brain();
	*this = copy;
}

Dog::~Dog(void){
	std::cout << BLU << "Destructor Dog called." << RESET << std::endl;
	delete this->_brain;
	return;
}

Dog& Dog::operator=(Dog const & src){
	if (this != &src){
		this->_type = src.getType();
		this->_brain = src._brain;
	}
	std::cout << BLU << "Copy assignment Dog operator called." << RESET << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const{
	std::cout << BLU << "The " << this->_type << " barks"<< RESET << std::endl;
}