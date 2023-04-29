/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:56:47 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 15:57:11 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	zombie;
	int		num = 5;

	zombie = zombieHorde(num, "Bob");
	for (int i = 0; i < num; i++){
		zombie[i].announce();
	}
	delete[] zombie;
	return (0);
}
