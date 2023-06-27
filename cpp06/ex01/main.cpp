/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:42:44 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/18 00:05:02 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void){
	Data		*ptr = new Data;
	Data		*dsr = NULL;
	uintptr_t	sr = 0;
	
	ptr->name = "Nanda";
	ptr->age = 25;
	ptr->height = 1.65;
		
	std::cout << CYN << "======Struct Data - before serialization======" << RESET << std::endl;
	std::cout << "Pointer: " << sr << std::endl;
	std::cout << "Name: " << ptr->name << std::endl;
	std::cout << "Age: " << ptr->age << std::endl;
	std::cout << "Height: " << ptr->height << std::endl;
	std::cout << CYN << "======Serialized Data========" << RESET << std::endl;
	sr = Serializer::serialize(ptr);
	std::cout << "Serialized pointer: " << sr << std::endl;
	std::cout << CYN << "======Deserialized Data======" << RESET << std::endl;
	dsr = Serializer::deserialize(sr);
	std::cout << "Deserialized pointer: " << dsr << std::endl;
	std::cout << "Deserialized name: " << dsr->name << std::endl;
	std::cout << "Deserialized age: " << dsr->age << std::endl;
	std::cout << "Deserialized height: " << dsr->height << std::endl;

	delete ptr;
	return (0);
}