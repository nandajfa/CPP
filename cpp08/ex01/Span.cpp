/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:38:15 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/27 01:25:35 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _maxNum(0) {
	return ;
}

Span::Span(unsigned int n){
	this->_maxNum = n;
	return ;
}

Span::~Span(void){
	return ;
}

Span::Span(Span const& copy){
	*this = copy;
}

Span& Span::operator=(Span const & src){
	if (this != &src){
		this->_maxNum = src._maxNum;
		this->_numbers = src._numbers;
	}
	return (*this);
}

void	Span::addNumber(int num){
	if (_numbers.size() >= _maxNum)
		throw std::runtime_error("Max span size reached.");
	_numbers.push_back(num);
}

int	Span::shortestSpan() {
	if (_numbers.size() <= 1)
		throw std::runtime_error("No span can be found.");
	std::vector<int> sortNum = _numbers;
	std::sort(sortNum.begin(), sortNum.end());
	
	int	shortest = sortNum[1] - sortNum[0];
	for (size_t i = 2; i < sortNum.size(); i++){
		int span = sortNum[i] - sortNum[i - 1];
		if (span < shortest)
			shortest = span;
	}
	return (shortest);
}

int	Span::longestSpan() {
	if (_numbers.size() <= 1)
		throw std::runtime_error("No span can be found.");
	
	std::vector<int> sortNum = _numbers;
	std::sort(sortNum.begin(), sortNum.end());
	
	std::vector<int>::iterator	minNum = sortNum.begin();
	std::vector<int>::iterator	maxNum = sortNum.end() - 1;

    return (*maxNum - *minNum);
}

void Span::addMoreNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	while (begin != end){
		addNumber(*begin);
		++begin;
	}
}
