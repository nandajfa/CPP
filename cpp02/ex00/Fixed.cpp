/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:52:57 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/24 14:57:33 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << GRN << "Default constructor called" << RESET << std::endl;
	this->_value = 0;
}

Fixed::~Fixed(){
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed::Fixed(Fixed const & src){
	std::cout << BLU << "Copy constructor called" << RESET << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs){
	std::cout << CYN << "Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}
