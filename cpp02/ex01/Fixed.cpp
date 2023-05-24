/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:52:57 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/24 15:00:28 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << GRN << "Default constructor called" << RESET << std::endl;
	this->_value = 0;
}

Fixed::Fixed(int const n) {
	std::cout << PRPL << "Int constructor called" << RESET << std::endl;
	this->_value = n << this->_fractionalBits;
}

Fixed::Fixed(float const f) {
	std::cout << ORNG << "Float constructor called" << RESET << std::endl;
	this->_value = (int) roundf(f * (1 << this->_fractionalBits));
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

Fixed::~Fixed(){
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / ((float)(1 << this->_fractionalBits)));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> this->_fractionalBits);
}

int Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

std::ostream & operator<<(std::ostream& o, Fixed const& fixed)
{
	o << fixed.toFloat();
	return(o);
}
