/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 01:54:08 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/20 20:57:03 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

#define CYN "\e[0;36m"
#define RESET "\e[0m"

template <typename T>
class Array {
	public:
		Array(void) : _elements(0), _size(0) {};
		
		Array(unsigned int n) : _elements(new T[n]), _size(n) {
			for (unsigned int i = 0; i < _size; i++){
				_elements[i] = T();
			}
		};
		
		Array(Array const& copy) : _elements(new T[copy._size]), _size(copy._size) {
			for (unsigned int i = 0; i < _size; i++)
				_elements[i] = copy._elements[i];
			*this = copy;
		}
		
		~Array(void) {
			delete[] _elements;
		};
		
		Array<T> & operator=(Array const & src) {
			if (this != &src){
				if (this->_elements)
					delete[] _elements;
				_elements = new T[src._size];
				_size = src._size;
				for (unsigned int i = 0; i < _size; i++)
					_elements[i] = src._elements[i];
			}
			return (*this);
		}
		
		T& operator[](unsigned int index) {
			if (index >= _size)
            	throw std::exception();
			return (_elements[index]);
		}
		
		unsigned int	size(void) const{
			return (_size);
		}
		
	private:
		T*	_elements;
		unsigned int	_size;
};

#endif