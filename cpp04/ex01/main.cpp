/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:33:58 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/29 00:40:30 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* animals[100];
	for (int i = 0; i < 50; i++){
		std::cout << "Dog number " << i + 1 << std::endl;
		animals[i] = new Dog();
	}
	for (int i = 50; i < 100; i++){
		std::cout << "Cat number " << i + 1 << std::endl;
		animals[i] = new Cat();
	}
	for (int i = 0; i < 100; i++) {
        std::cout << "Delete animal " << i + 1 << std::endl;
		delete animals[i];
    }
	std::cout << std::endl;

	return (0);
}
