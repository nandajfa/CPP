/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:52:54 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/24 16:14:17 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

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

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;

		Fixed& operator=(Fixed const & rhs);

		bool operator > (Fixed const & fixed) const;
		bool operator < (Fixed const & fixed) const;
		bool operator >= (Fixed const & fixed) const;
		bool operator <= (Fixed const & fixed) const;
		bool operator == (Fixed const & fixed) const;
		bool operator != (Fixed const & fixed) const;

		Fixed operator + (Fixed const & fixed) const;
		Fixed operator - (Fixed const & fixed) const;
		Fixed operator * (Fixed const & fixed) const;
		Fixed operator / (Fixed const & fixed) const;

		Fixed& operator++(void); /*pre-increment*/
		Fixed& operator--(void); /*pre-decrement*/
		Fixed operator++(int); /*post-increment*/
		Fixed operator--(int); /*post-decrement*/

		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed const & min(Fixed const& a, Fixed const & b);
		static Fixed& max(Fixed& a, Fixed& b);
		static Fixed const & max(Fixed const& a, Fixed const & b);
};

std::ostream & operator<<(std::ostream & o, Fixed const & fixed);

#endif
