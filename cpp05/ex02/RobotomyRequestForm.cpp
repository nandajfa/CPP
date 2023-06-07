/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:03:36 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/07 01:11:26 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Robotomy Request Form", 72, 45), _target("None") {
	std::cout << GRN << "Default constructor Robotomy Request called." << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& copy) : AForm() {
	std::cout << GRN << "Copy constructor Robotomy Request called." << RESET << std::endl;
	*this = copy;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	AForm("Robotomy Request Form", 72, 45), 
	_target(target) {
	std::cout << GRN << "Constructor Robotomy Request with parameters called." << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src){
	std::cout << GRN << "Copy assignment operator PRobotomy Request called." << RESET << std::endl;
	if (this != &src){
		this->_target = src._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << RED << "Destructor Robotomy Request called." << RESET << std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const{
	this->checkRequirements(executor);
	
	std::cout << "Drilling noises..." << std::endl;
	int	success = rand() % 2;
	if (success == 0)
		std::cout << this->_target << " has been successfully robotomized" << std::endl;
	else
		std::cout << this->_target << " fail to be robotized." << std::endl;
}