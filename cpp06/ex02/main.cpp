/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:10:42 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/18 03:03:12 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

#define CYN "\e[0;36m"
#define RESET "\e[0m"

Base * generate(void){
	srand(static_cast<unsigned int>(time(0)));
	int	random = rand() % 3;
	
	Base* base = NULL;
	switch (random) {
		case 0:
			base = new A;
			break ;
		case 1:
			base = new B;
			break ;
		case 2:
			base = new C;
			break ;	
	}
	return (base);
}

void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer Type A." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer Type B." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer Type C." << std::endl;
	else
		std::cout << "Invalid pointer." << std::endl;
}

void identify(Base& p){
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "Reference type A." << std::endl;
	}
	catch (std::exception &e){
		std::cout << "Invalid A: " << e.what() << std::endl;
	}
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "Reference type B." << std::endl;
	}
	catch (std::exception &e){
		std::cout << "Invali B: " << e.what() << std::endl;
	}
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "Reference type C." << std::endl;
	}
	catch (std::exception &e){
		std::cout << "Invalid C: " << e.what() << std::endl;
	}	
}

int	main(void){
	std::cout << CYN << "==Real type==" << RESET << std::endl;
	Base*	p = generate();
	Base&	r = *p;
	
	identify(p);
	identify(r);
	delete p;
	
	std::cout << CYN << "==Invalid type==" << RESET << std::endl;
	Base* invalid = new Base();
	identify(invalid);
	identify(*invalid);
	delete invalid;
	return(0);
}