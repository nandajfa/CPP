/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:08:36 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 15:58:34 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
	return;
}
HumanB::~HumanB( void ){
	return;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack()
{
	  std::cout << BHGRN << this->_name << " attacks";
        if (this->_weapon != nullptr)
            std::cout << " with their " << this->_weapon->getType();
        else
            std::cout << " unarmed";
        std::cout << RESET << std::endl;
}
