/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:33:58 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/03 18:06:54 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/**
 * @brief Construct a new AAnimal::AAnimal object
 *
 */
AAnimal::AAnimal(void) : _type("AAnimal") {
	std::cout << GRN << "Default constructor AAnimal called." << RESET << std::endl;
	return;
}

/**
 * @brief Construct copy a new AAnimal::AAnimal object
 *
 * @param copy
 */
AAnimal::AAnimal(AAnimal const& copy){
	std::cout << GRN << "Copy constructor AAnimal called." << RESET << std::endl;
	*this = copy;
}

/**
 * @brief Destroy the AAnimal::AAnimal object
 *
 */
AAnimal::~AAnimal(void){
	std::cout << GRN << "Destructor AAnimal called." << RESET << std::endl;
	return;
}

/**
 * @brief Copy assignment operator for AAnimal.
 *
 * @param src The source AAnimal object to be copied.
 * @return AAnimal& A reference to the modified AAnimal object.
 */
AAnimal& AAnimal::operator=(AAnimal const & src){
	if (this != &src)
		this->_type = src.getType();
	std::cout << GRN << "Copy assignment AAnimal operator called." << RESET << std::endl;
	return (*this);
}
/**
 * @brief Get the type of the AAnimal object.
 *
 * @return std::string A string representing the type of the AAnimal.
 */
std::string	AAnimal::getType(void) const{
	return(this->_type);
}

/**
 * @brief Set the type of the AAnimal object.
 *
 * @param type The string representing the type of the AAnimal.
 */
void	AAnimal::setType(std::string type){
	this->_type = type;
}

 /**
  * @brief Make a sound.
  * @details This function prints a message indicating that the animal does not make sounds.
  */
void	AAnimal::makeSound(void) const{
	std::cout << GRN << "This " << this->_type << " does not make sounds."  << RESET << std::endl;
}
