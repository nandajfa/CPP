/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:03:26 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/20 15:10:42 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("Presidential Pardon Form", 25, 5), _target("None") {
	std::cout << GRN << "Default constructor Presidential Pardon called." << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& copy) : AForm() {
	std::cout << GRN << "Copy constructor Presidential Pardon called." << RESET << std::endl;
	*this = copy;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
	AForm("Presidential Pardon Form", 25, 5), 
	_target(target) {
	std::cout << GRN << "Constructor Presidential Pardon with parameters called." << RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src){
	std::cout << GRN << "Copy assignment operator Presidential Pardon called." << RESET << std::endl;
	if (this != &src){
		this->_target = src._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << RED << "Destructor Presidential Pardon called." << RESET << std::endl;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const{
	this->checkRequirements(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}
