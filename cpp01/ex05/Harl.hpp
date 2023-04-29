/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:08:42 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 19:29:22 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

#define BBLU "\e[1;34m"
#define BRED "\e[1;31m"
#define BCYN "\e[1;36m"
#define BGRN "\e[1;32m"
#define BMAG "\e[1;35m"
#define BWHT "\e[1;37m"
#define RESET "\e[0m"

class Harl {
	public:
	Harl( void );
	~Harl( void );
	void complain( std::string level );

	private:
	void _debug( void );
	void _info( void );
	void _warning( void );
	void _error( void );
};

#endif
