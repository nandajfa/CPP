/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 00:55:10 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 15:56:59 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

#define RESET "\033[0m"
#define CYAN "\033[36;1m"
#define BBLU "\e[1;34m"
#define RED "\033[31m"
#define BGRN "\e[1;32m"

class Zombie {
private:
	std::string	_name;
public:
	Zombie(std::string name);
	~Zombie( void );
	void announce( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
