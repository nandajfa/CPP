/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:56:53 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 15:57:37 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"

class Zombie {

private:
	std::string	_name;

public:
	Zombie( void );
	~Zombie( void );
	void	announce( void );
	void	setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
