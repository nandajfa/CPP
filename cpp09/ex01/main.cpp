/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 23:05:06 by jefernan          #+#    #+#             */
/*   Updated: 2023/07/01 22:50:56 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2){
		std::cout << "Wrong number of arguments. Usage: ./RPN <expression>." << std::endl;
		return (1);
	}
	try {
		RPN rpn(argv[1]);
		rpn.rpn();
		
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}