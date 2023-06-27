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
	std::cout << YEL << "Default constructor Cat called." << RESET << std::endl;
	return;
}

Cat::Cat(Cat const& copy) : Animal() {
	std::cout << YEL << "Copy constructor Cat called." << RESET << std::endl;
	*this = copy;
}

Cat::~Cat(void){
	std::cout << YEL << "Destructor Cat called." << RESET << std::endl;
	return;
}

Cat& Cat::operator=(Cat const & src){
	if (this != &src)
		this->setType(src.getType());
	std::cout << YEL << "Copy assignment Cat operator called." << RESET << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const{
	std::cout << BLU << "The " << this->_type << " miaawws"<< RESET << std::endl;
}
