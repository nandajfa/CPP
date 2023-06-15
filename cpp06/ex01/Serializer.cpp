/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:42:41 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/16 01:27:52 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void){
	return ;
}

Serializer::Serializer(Serializer const& copy){
	(void) copy;
}

Serializer::~Serializer(void){
	return ;
}

Serializer& Serializer::operator=(Serializer const & src){
	(void) src;
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}
