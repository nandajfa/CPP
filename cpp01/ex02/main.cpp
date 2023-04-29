/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:31:07 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 15:57:58 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#define CYN "\e[0;36m"
#define GRN "\e[0;32m"
#define RESET "\e[0m"

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << std::endl;
	std::cout << CYN << "The memory address of the string variable is: " << &string << std::endl;
	std::cout << "The memory address held by stringPTR is: " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF is: " << &stringREF << RESET << std::endl;

	std::cout << std::endl;
	std::cout << GRN << "The value of the string variable is: " << string << std::endl;
	std::cout << "The value pointed to by stringPTR is: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF is: " << stringREF << RESET << std::endl;
	return (0);
}
