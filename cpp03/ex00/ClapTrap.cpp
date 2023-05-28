/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:22:35 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/28 19:06:14 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hitPoints(10), _energyPoints(10), _attackDamage(0), _name("Robot"){
	std::cout << GRN << "Default constructor called." << RESET << std::endl;
	return;
}
ClapTrap::ClapTrap(std::string const& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << GRN << "Constructor with parameter name called" << RESET << std::endl;
}
ClapTrap::ClapTrap(ClapTrap const& copy){
	std::cout << GRN << "Copy constructor called." << RESET << std::endl;
	*this = copy;
}
ClapTrap::~ClapTrap(void){
	std::cout << GRN << "Destructor from ClapTrap " << this->getName() << " called." << RESET << std::endl;
	return;
}

ClapTrap& ClapTrap::operator=(ClapTrap const & src){
	if (this != &src){
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	}
	std::cout << GRN << "Copy assignment operator called." << RESET << std::endl;
	return (*this);
}

void ClapTrap::setName( std::string const &name ){
	this->_name = name;
}

void ClapTrap::setHitPoints( int hitPoints ){
	this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints( int energy ){
	this->_energyPoints = energy;
}

void ClapTrap::setAttackDamage( int attack ){
	this->_attackDamage = attack;
}

std::string ClapTrap::getName( void ) const{
	return (this->_name);
}

int ClapTrap::getHitPoints( void ) const{
	return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints( void ) const{
	return (this->_energyPoints);
}

int ClapTrap::getAttackDamage( void ) const{
	return (this->_attackDamage);
}

void ClapTrap::attack(const std::string& target){
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0){
		std::cout << BLU << "ClapTrap " << this->getName();
		std::cout << " attacks " << target << ", causing " << this->getAttackDamage();
		std::cout << " points of damage!" << RESET << std::endl;
		this->_energyPoints--;
	} else {
		if (this->getEnergyPoints() <= 0)
			std::cout << "ClapTrap " << this->getName() << ", has no energy points." << std::endl;
		if (this->getHitPoints() <= 0)
			std::cout << "ClapTrap " << this->getName() << ", has no hit points." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if ((int)amount > 0) {
		this->_hitPoints -= (int)amount;
		std::cout << MAG << "ClapTrap " << this->getName();
		std::cout << " takes " << amount << " points of damage. Total hit points: ";
		std::cout << this->getHitPoints() << RESET << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0 && (int)amount >= 0){
		std::cout << CYN << "ClapTrap " << this->getName();
		std::cout << " repairs itself. It gets " << amount << " hit points back." << RESET << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	} else {
		if (this->getEnergyPoints() <= 0){
			std::cout << CYN << "ClapTrap " << this->getName() << ", unable to repair itself. Energy point = ";
			std::cout << this->getEnergyPoints() << RESET << std::endl;
		}
		if (this->getHitPoints() <= 0){
			std::cout << CYN << "ClapTrap " << this->getName() << ", unable to repair itself. Hit points = ";
			std::cout << this->getHitPoints() << RESET << std::endl;
		}
	}
}
