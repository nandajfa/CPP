/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:52:54 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/24 14:57:41 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define BLU "\e[0;34m"
#define CYN "\e[0;36m"
#define RESET "\e[0m"

class	Fixed{
	private:
		int	_value;
		static const int _fractionalBits = 8;

	public:
		Fixed( void );
		Fixed(Fixed const & src);
		~Fixed( void );
		Fixed& operator=(Fixed const & rhs);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
