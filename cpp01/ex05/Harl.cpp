/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:08:38 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 19:29:32 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void){
	return ;
}
Harl::~Harl(void){
	return ;
}

void Harl::_debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. "
		<< "I really do!" << std::endl;
}

void Harl::_info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put "
		<< "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for "
		<< "years whereas you started working here since last month." << std::endl;
}

void Harl::_error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	void (Harl::*msgFunctions[4])(void) = { &Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error };
	std::string	levels[4] = {"debug", "info", "warning", "error"};
	int i;

	i = 0;
	while (i < 4)
	{
		if (!levels[i].compare(level)){
			(this->*msgFunctions[i])();
			return ;
		}
		i++;
	}
	std::cout << BBLU << "Invalid complain level: " << level << RESET << std::endl;
}
