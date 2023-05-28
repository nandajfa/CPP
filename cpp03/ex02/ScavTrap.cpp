/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 02:40:53 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/28 19:11:03 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap() {
	this->setName("Robot");
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << GRN << "Default constructor from ScavTrap called." << RESET << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string const & name) : ClapTrap(name) {
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << GRN << "Constructor with parameter name from ScavTrap called." << RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& copy): ClapTrap() {
	std::cout << GRN << "Copy constructor from ScavTrap called." << RESET << std::endl;
	*this = copy;
}
ScavTrap::~ScavTrap(void) {
	std::cout << GRN << "Destructor from ScavTrap ";
	std::cout << this->getName() << " called." << RESET << std::endl;
	return;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & src){
	if (this != &src){
		this->setName(src.getName());
		this->setHitPoints(src.getHitPoints());
		this->setEnergyPoints(src.getEnergyPoints());
		this->setAttackDamage(src.getAttackDamage());
	}
	std::cout << GRN << "Copy assignment operator from ScavTrap ";
	std::cout << this->getName() << " called." << RESET << std::endl;
	return (*this);
}

void ScavTrap::attack(const std::string& target){
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0){
		std::cout << BLU << "ScavTrap " << this->getName();
		std::cout << " attacks " << target << ", causing " << this->getAttackDamage();
		std::cout << " points of damage!" << RESET << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	} else {
		if (this->getEnergyPoints() <= 0)
			std::cout << "ScavTrap " << this->getName() << ", has no energy points." << std::endl;
		if (this->getHitPoints() <= 0)
			std::cout << "ScavTrap " << this->getName() << ", has no hit points." << std::endl;
	}
}

void	ScavTrap::guardGate( void ){
	std::cout << "ScavTrap " << this->getName();
	std::cout << " is now in Gate keeper mode." << std::endl;
}
