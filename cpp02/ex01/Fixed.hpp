/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:52:54 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/24 15:00:37 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

#define RED		"\e[0;31m"
#define GRN		"\e[0;32m"
#define BLU 	"\e[0;34m"
#define CYN		"\e[0;36m"
#define PRPL	"\033[38;5;200m"
#define ORNG	"\033[0;38;5;166m"
#define RESET	"\e[0m"

class	Fixed{
	private:
		int	_value;
		static const int _fractionalBits = 8;

	public:
		Fixed( void );
		Fixed(int const n);
		Fixed(float const f);
		Fixed(Fixed const & src);
		~Fixed( void );

		Fixed& operator=(Fixed const & rhs);

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & fixed);

#endif
