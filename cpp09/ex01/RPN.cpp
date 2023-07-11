/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 23:04:59 by jefernan          #+#    #+#             */
/*   Updated: 2023/07/03 14:52:23 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {
	return ;
}

RPN::RPN(std::string input) : _input(input) {
	return ;	
}

RPN::~RPN(void){
	return ;
}

RPN::RPN(RPN const& copy){
	*this = copy;
}

RPN& RPN::operator=(RPN const & src){
	if (this != &src){
		this->_input = src._input;
		this->_stack = src._stack;
	}
	return (*this);
}

void	RPN::rpn(){
	_validateInput();
	_getResult();
}

void	RPN::_validateInput(){
	std::string tokens = "+-*/";
	
	if (this->_input.find_first_of(tokens) == std::string::npos)
		throw std::runtime_error("Error: invalid expression, no tokens.");
	for (size_t i = 0; i < _input.length(); i++){
		if (std::isspace(_input[i]))
			continue;
		if (i == 0 && _isTokens(_input[i]))
			throw std::runtime_error("Error: invalid expression.");
		if (std::isdigit(_input[i]) && std::isspace(_input[i + 1])){
			_stack.push(_input[i] - '0');
		} else if (_isTokens(_input[i]))
			_calculateRPN(_input[i]);
		else
			throw std::runtime_error("Error: invalid expression.");
	}
}

bool	RPN::_isTokens(char c){
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return (true);
	return (false);
}

void	RPN::_calculateRPN(char c){
	if (this->_stack.size() < 2)
		throw std::runtime_error("Error: Insufficient operands.");
	int op2 = this->_stack.top();
	_stack.pop();
	int op1 = this->_stack.top();
	_stack.pop();
	int result = 0;
	
	if (c == '+')
		result = op1 + op2;
	else if (c == '-')
		result = op1 - op2;
	else if (c == '*')
		result = op1 * op2;
	else if (c == '/'){
		if (op2 == 0)
			throw std::runtime_error("Error: Division by zero.");
		result = op1 / op2;
	}
	
	this->_stack.push(result);
}

void	RPN::_getResult(){
	if (this->_stack.size() != 1) {
        throw std::runtime_error("Error: Invalid expression.");
    }
	std::cout << this->_stack.top() << std::endl;
}
