/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:41:08 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/20 16:40:40 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename Func>
void iter(T* array, size_t length, Func function){
	for (size_t i = 0; i < length; i++){
		function(array[i]);
	}
}

template <typename T>
void printElement(const T& element){
	std::cout << "Array element: " << element << std::endl;
}

#endif