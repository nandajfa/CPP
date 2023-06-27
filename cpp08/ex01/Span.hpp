/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:38:12 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/27 01:23:50 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class Span {
	public:
		Span(void);
		Span(unsigned int n);
		~Span(void);
		Span(Span const& copy);

		Span& operator=(Span const & src);
		
		unsigned int getNumbers(void) const;
		unsigned int getMaxNum(void) const;
		
		void	addNumber(int num);
		int		shortestSpan();
		int		longestSpan();
		void	addMoreNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		
	private:
		unsigned int		_maxNum;
		std::vector<int>	_numbers;	
};

#endif
