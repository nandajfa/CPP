/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:08:46 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 19:29:13 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << BBLU << "----Harl Complains----" << RESET << std::endl;
	std::cout << BCYN << "====DEBUG====" << RESET << std::endl;
	harl.complain("debug");
	std::cout << std::endl;
	std::cout << BGRN << "====INFO====" << RESET << std::endl;
	harl.complain("info");
	std::cout << std::endl;
	std::cout << BMAG << "====WARNING====" << RESET << std::endl;
	harl.complain("warning");
	std::cout << std::endl;
	std::cout << BRED << "====ERROR====" << RESET << std::endl;
	harl.complain("error");
	std::cout << std::endl;
	harl.complain("invalid");
	return (0);
}
