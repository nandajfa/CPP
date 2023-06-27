/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:09:44 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/22 21:09:11 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main(void)
{
	std::vector<int> v1;
	std::vector<int>::iterator it;
	
	for (int i = 0; i < 100; i++){
		v1.push_back(i);
	}

	try {
		it = easyfind(v1, 76);
		std::cout << BLU << "Number: " << *it << RESET << std::endl;
	}
	catch (std::exception &e){
		std::cout << RED << e.what() << RESET << std::endl;
	}

	try {
		it = easyfind(v1, 110);
		std::cout << BLU << "Number: " << *it << RESET << std::endl;
	}
	catch (std::exception &e){
		std::cout << RED << e.what() << RESET << std::endl;
	}
	return (0);
}
