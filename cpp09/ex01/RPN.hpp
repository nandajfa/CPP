/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 23:04:57 by jefernan          #+#    #+#             */
/*   Updated: 2023/07/01 23:53:45 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN {
	public:
		RPN(void);
		RPN(std::string input);
		~RPN(void);
		RPN(RPN const& copy);

		RPN& operator=(RPN const & src);

		void	rpn();
	private:
		std::string		_input;
		std::stack<int> _stack;
		void	_validateInput();
		bool	_isTokens(char c);
		void	_calculateRPN(char c);
		void	_getResult();
};

#endif