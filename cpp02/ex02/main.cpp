/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:52:51 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/24 16:14:30 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << ORNG << "===subject main===" << RESET << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << ORNG << "===end of subject main===" << RESET << std::endl;

	Fixed c(42);
	Fixed d(5.18f);
	a = c;

	std::cout << ORNG << "Arithmetic operators" << RESET << std::endl;
	Fixed e = c + a;
	std::cout << e << std::endl;

	e = b - d;
	std::cout << e << std::endl;

	e = c * a;
	std::cout << e << std::endl;

	e = c / d;
	std::cout << e << std::endl;

	std::cout << ORNG << "Comparison operators" << RESET << std::endl;
	std::cout << "a= "<< a << " b= " << b << " c= " << c << " d= " << d << " e= " << e << std::endl;
	std::cout << "b > c: " << (b > c) << std::endl;
    std::cout << "c < d: " << (c < d) << std::endl;
    std::cout << "e >= a: " << (e >= a) << std::endl;
    std::cout << "d <= b: " << (d <= b) << std::endl;
    std::cout << "a == c: " << (a == c) << std::endl;
    std::cout << "b != c: " << (b != c) << std::endl;

	std::cout << ORNG << "increment and decrement operators" << RESET << std::endl;
	std::cout << "++c: " << ++c << std::endl;
    std::cout << "c--: " << c-- << std::endl;
    std::cout << "d++: " << d++ << std::endl;
    std::cout << "--e: " << --e << std::endl;

	std::cout << ORNG << "Int and float conversion" << RESET << std::endl;
	float floatValue = a.toFloat();
    int intValue = d.toInt();
    std::cout << "a to float: " << floatValue << std::endl;
    std::cout << "d to int: " << intValue << std::endl;

	std::cout << ORNG << "Min and Max" << RESET << std::endl;
	Fixed x(10);
    Fixed y(20);
    Fixed f = Fixed::min(x, y);
    std::cout << "min(x, y): " << f << std::endl;

    Fixed g = Fixed::max(x, y);
    std::cout << "max(x, y): " << g << std::endl;

	return 0;
}
