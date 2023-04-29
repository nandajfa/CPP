/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:05:04 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 15:56:16 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	bob = Zombie("Bob");
	Zombie*	ted = newZombie("Ted");

	std::cout << CYAN << std::endl <<"Zombie on stack:" << RESET << std::endl;
	bob.announce();

	std::cout << BGRN << std::endl << "Zombie on heap:" << RESET << std::endl;
	ted->announce();

	std::cout <<  BBLU << std::endl << "Function randomChump" << RESET << std::endl;
	randomChump("Chris");

	delete(ted);
	return (0);
}
