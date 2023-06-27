/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:09:41 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/22 13:50:41 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

#define BLU "\e[0;34m"
#define RED "\e[0;31m"
#define RESET "\e[0m"

class NotFoundException : public std::exception {
	virtual const char* what() const throw(){
		return ("Value not found in container.");
	};
};

template<typename T>
typename T::iterator	easyfind(T &cont, int n){
	typename T::iterator	it;

	it = std::find(cont.begin(), cont.end(), n);
	if (it == cont.end()) {
        throw ::NotFoundException();
    }
    return it;
}


#endif