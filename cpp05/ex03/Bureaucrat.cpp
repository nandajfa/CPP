/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 23:13:24 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/07 00:40:11 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Ted"), _grade(1) {
	std::cout << GRN << "Default constructor Bureaucrat called." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& copy){
	std::cout << GRN << "Copy constructor Bureaucrat called." << RESET << std::endl;
	*this = copy;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
	std::cout << GRN << "Constructor Bureaucrat with parameters called." << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src){
	std::cout << GRN << "Copy assignment operator Bureaucrat called." << RESET << std::endl;
	if (this != &src){
		this->_name = src.getName();
		this->_grade = src.getGrade();	
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(){
	std::cout << RED << "Destructor Bureaucrat called." << RESET << std::endl;
}

std::string Bureaucrat::getName(void) const{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void	Bureaucrat::increment(void){
	if (this->_grade > 1)
		this->_grade--;
	else
		throw GradeTooHighException();
}

void Bureaucrat::decrement(void){
	if (this->_grade < 150)
		this->_grade++;
	else
		throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Bureaucrat too high, maximum grade is 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Bureaucrat too low, minimum grade is 150");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& br){
	os << CYN << br.getName() << ", bureaucrat grade: " << br.getGrade() << RESET;
	return (os);
}

void Bureaucrat::signForm(AForm& form){
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << "." << std::endl;
	} catch (std::exception& e) {
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form){
	try {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Execution failed: " << e.what() << std::endl;
    }
}