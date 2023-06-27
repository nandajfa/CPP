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

int main()
{
	const Animal*		meta = new Animal();
	const Animal*		j = new Dog();
	const Animal*		i = new Cat();
	const WrongAnimal*	wrg = new WrongAnimal();
	const WrongAnimal*	wrgC = new WrongCat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << wrg->getType() << " " << std::endl;
	std::cout << wrgC->getType() << " " << std::endl;
	std::cout << std::endl;

	j->makeSound();
	i->makeSound();
	meta->makeSound();
	wrg->makeSound();
	wrgC->makeSound();
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	delete wrg;
	delete wrgC;
	
	std::cout << std::endl;

	return (0);
}
