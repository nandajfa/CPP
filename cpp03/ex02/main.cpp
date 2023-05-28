/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:22:41 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/28 19:10:49 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main()
{
	{
		ClapTrap	ct1;
		for (int i = ct1.getEnergyPoints(); 0 < ct1.getEnergyPoints(); ct1.setEnergyPoints(--i)){
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
		FragTrap	rb1;
		FragTrap	rb2("rb2");
		FragTrap	rb2Cpy = rb2;
		FragTrap	rb3(rb1);

		rb1.highFivesGuys();
		rb1.attack(rb2.getName());
		rb2.beRepaired(15);

		rb2Cpy.highFivesGuys();
		rb2Cpy.attack(rb3.getName());
		rb2Cpy.takeDamage(rb2Cpy.getAttackDamage());
		std::cout << std::endl;

		rb2.highFivesGuys();
		rb2.attack(rb2Cpy.getName());
		rb2Cpy.takeDamage(rb2Cpy.getAttackDamage());
		rb2Cpy.beRepaired(5);
		std::cout << std::endl;

		rb3.highFivesGuys();
		rb3.attack(rb1.getName());
		rb1.takeDamage(rb1.getAttackDamage());
		rb1.beRepaired(2);
		std::cout << std::endl;

		rb2Cpy.setEnergyPoints(0);
		rb2Cpy.attack(rb3.getName());
		rb2Cpy.beRepaired(3);
		std::cout << std::endl;
	}
	return (0);
}
