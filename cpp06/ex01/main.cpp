/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:42:44 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/16 01:49:40 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void){
	Data	*ptr = new Data;
	
	ptr->name = "Nanda";
	ptr->age = 25;
	ptr->height = 1.65;
		
	std::cout << "======Struct Data======" << std::endl;
	std::cout << "Name: " << ptr->name << std::endl;
	std::cout << "Age: " << ptr->age << std::endl;
	std::cout << "Height: " << ptr->height << std::endl;
	uintptr_t	sr = Serializer::serialize(ptr);
	std::cout << "======Deserialize======" << std::endl;
	std::cout << "Deserialized name: " << Serializer::deserialize(sr)->name << std::endl;
	std::cout << "Deserialized age: " << Serializer::deserialize(sr)->age << std::endl;
	std::cout << "Deserialized height: " << Serializer::deserialize(sr)->height << std::endl;
	
	return (0);
}