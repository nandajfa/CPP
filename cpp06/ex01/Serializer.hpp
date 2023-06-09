/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:42:38 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/18 00:04:11 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

#define CYN "\e[0;36m"
#define RESET "\e[0m"

struct Data {
	std::string	name;
    int 		age;
    double		height;
};

class Serializer {
	public:
		~Serializer(void);
		
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
	private:
		Serializer(void);
		Serializer(Serializer const& copy);
		Serializer& operator=(Serializer const & src);	
};

#endif