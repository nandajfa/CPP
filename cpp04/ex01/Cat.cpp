/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:33:58 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/29 00:40:30 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	this->setType("Cat");
	this->_brain = new Brain();
	std::cout << YEL << "Default constructor Cat called." << RESET << std::endl;
	return;
}

Cat::Cat(Cat const& copy) : Animal() {
	std::cout << YEL << "Copy constructor Cat called." << RESET << std::endl;
	this->setType(copy._type);
	this->_brain = new Brain();
	*this = copy;
}

Cat::~Cat(void){
	std::cout << YEL << "Destructor Cat called." << RESET << std::endl;
	delete (this->_brain);
	return;
}

Cat& Cat::operator=(Cat const & src){
	if (this != &src){
		this->setType(src.getType());
		*(this->_brain) = *(src.getBrain());
	}
	std::cout << YEL << "Copy assignment Cat operator called." << RESET << std::endl;
	return (*this);
}

Brain*	Cat::getBrain(void) const{
	return (this->_brain);
}

void	Cat::makeSound(void) const{
	std::cout << BLU << "The " << this->_type << " miaawws"<< RESET << std::endl;
}
