/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:22:41 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/28 19:08:23 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	{
		ClapTrap	ct1;
		for (int i = ct1.getEnergyPoints(); 0 < ct1.getEnergyPoints();
			ct1.setEnergyPoints(--i)){
			ct1.attack("ct2");
		}
		ct1.attack("ct3");
		std::cout << std::endl;
	}
	{
		ClapTrap	ct;

		while (ct.getHitPoints())
			ct.takeDamage(5);
		ct.attack("ct1");
		std::cout << std::endl;
	}
	{
		ScavTrap	rb1;
		ScavTrap	rb2("rb2");
		ScavTrap	rb2Cpy = rb2;

		std::cout << BWHT << "Rb1 attacks rb2" << RESET << std::endl;
		rb1.attack(rb2.getName());
		rb2.takeDamage(rb2.getAttackDamage());
		rb2.beRepaired(15);
		rb2.guardGate();
		std::cout << std::endl;

		std::cout << BWHT << "Rb2 attacks rb2 copy" << RESET << std::endl;
		rb2.attack(rb2Cpy.getName());
		rb2Cpy.takeDamage(rb2Cpy.getAttackDamage());
		rb2Cpy.beRepaired(5);
		rb2Cpy.guardGate();
		std::cout << std::endl;

		std::cout << BWHT << "Rb2Cpy attacks rb1" << RESET << std::endl;
		rb2Cpy.setEnergyPoints(0);
		rb2Cpy.attack(rb1.getName());
		rb2Cpy.guardGate();
		std::cout << std::endl;
	}

	return (0);
}
