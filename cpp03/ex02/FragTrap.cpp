/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 01:42:53 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/28 19:10:33 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap() {
	this->setName("Robot");
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << GRN << "Default constructor from FragTrap called." << RESET << std::endl;
	return;
}

FragTrap::FragTrap(std::string const & name) : ClapTrap(name) {
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << GRN << "Constructor with parameter name from FragTrap called." << RESET << std::endl;
}

FragTrap::FragTrap(FragTrap const& copy): ClapTrap() {
	std::cout << GRN << "Copy constructor from FragTrap called." << RESET << std::endl;
	*this = copy;
}
FragTrap::~FragTrap(void) {
	std::cout << GRN << "FragTrap ";
	std::cout << this->getName() << " destroyed." << RESET << std::endl;
	return;
}

FragTrap& FragTrap::operator=(FragTrap const & src){
	if (this != &src){
		this->setName(src.getName());
		this->setHitPoints(src.getHitPoints());
		this->setEnergyPoints(src.getEnergyPoints());
		this->setAttackDamage(src.getAttackDamage());
	}
	std::cout << GRN << "Copy assignment operator from FragTrap ";
	std::cout << this->getName() << " called." << RESET << std::endl;
	return (*this);
}

void FragTrap::attack(const std::string& target){
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0){
		std::cout << BLU << "FragTrap " << this->getName();
		std::cout << " attacks " << target << ", causing " << this->getAttackDamage();
		std::cout << " points of damage!" << RESET << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	} else {
		if (this->getEnergyPoints() <= 0)
			std::cout << "FragTrap " << this->getName() << ", has no energy points." << std::endl;
		if (this->getHitPoints() <= 0)
			std::cout << "FragTrap " << this->getName() << ", has no hit points." << std::endl;
	}
}

void	FragTrap:: highFivesGuys( void ){
	std::cout << this->getName();
	std::cout << ": High five guys!" << std::endl;
}
