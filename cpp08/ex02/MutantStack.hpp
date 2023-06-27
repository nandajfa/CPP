/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:36:33 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/27 20:20:26 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

#define CYN "\e[0;36m"
#define RESET "\e[0m"


template<typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack<T>(void) {};
		~MutantStack<T>(void) {};
		MutantStack<T>(MutantStack const& copy){
			*this = copy;
		}
		MutantStack<T>& operator=(MutantStack<T> const & src){
			*this = src;
			return (*this);
		}
		
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() {
			return (this->c.begin());
		}

		iterator end() {
			return (this->c.end());
		}
	
};

#endif


