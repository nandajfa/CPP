/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:22:41 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/28 19:06:31 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	viper;
	ClapTrap	shadow;
	ClapTrap	thunder("Thunder");
	ClapTrap	thunderCpy = thunder;
	ClapTrap	storm(thunderCpy);

	std::cout << BWHT << "Viper attacks Shadow" << RESET << std::endl;
	viper.attack(shadow.getName());
	shadow.takeDamage(shadow.getAttackDamage());
	shadow.beRepaired(10);
	std::cout << std::endl;

	std::cout << BWHT << "Shadow attacks thunder" << RESET << std::endl;
	shadow.attack(thunder.getName());
	thunder.takeDamage(thunder.getAttackDamage());
	thunder.beRepaired(5);
	std::cout << std::endl;

	std::cout << BWHT << "Thunder attacks storm" << RESET << std::endl;
	thunder.attack(storm.getName());
	storm.takeDamage(storm.getAttackDamage());
	storm.beRepaired(6);
	std::cout << std::endl;

	std::cout << BWHT << "Storm attacks viper" << RESET << std::endl;
	storm.attack(viper.getName());
	viper.takeDamage(viper.getAttackDamage());
	viper.beRepaired(4);
	std::cout << std::endl;

	std::cout << BWHT << "Viper attacks thunderCpy" << RESET << std::endl;
	thunderCpy.takeDamage(10);
	viper.attack(thunderCpy.getName());
	thunderCpy.beRepaired(2);
	std::cout << std::endl;

	std::cout << BWHT << "ThunderCpy attacks Shadow" << RESET << std::endl;
	thunderCpy.setEnergyPoints(0);
	thunderCpy.attack(shadow.getName());
	std::cout << std::endl;

	std::cout << BWHT << "ThunderCpy attacks Thunder" << RESET << std::endl;
	thunder.setEnergyPoints(0);
	thunderCpy.attack(thunder.getName());
	thunder.beRepaired(3);
	std::cout << std::endl;
	return (0);
}
