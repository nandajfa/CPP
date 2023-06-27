/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 23:07:56 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/20 16:40:35 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

#define GRN "\e[0;32m"
#define RESET "\e[0m"

template <typename T>
void	swap(T &a, T &b){
	T aux;
	
	aux = a;
	a = b;
	b = aux;
}

template <typename T>
T const &min(T const &a, T const &b){
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T const &max(T const &a, T const &b){
	if (a > b)
		return (a);
	return (b);
}

#endif
