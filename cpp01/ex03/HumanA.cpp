/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:08:38 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 15:58:17 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
	return;
}
HumanA::~HumanA(void){
	return;
}

void HumanA::attack(void){
	std::cout << HCYN << this->_name << "attacks with their" << _weapon.getType() << RESET << std::endl;
}
