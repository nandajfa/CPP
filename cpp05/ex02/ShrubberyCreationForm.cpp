/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 02:45:55 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/07 02:58:51 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Shrubbery Creation Form", 145, 137), _target("Home") {
	std::cout << GRN << "Default constructor ShrubberyCreationForm called." << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& copy) : AForm() {
	std::cout << GRN << "Copy constructor ShrubberyCreationForm called." << RESET << std::endl;
	*this = copy;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
	AForm("Shrubbery Creation Form", 145, 137), 
	_target(target) {
	std::cout << GRN << "Constructor ShrubberyCreationForm with parameters called." << RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src){
	std::cout << GRN << "Copy assignment operator ShrubberyCreationForm called." << RESET << std::endl;
	if (this != &src){
		this->_target = src._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << RED << "Destructor ShrubberyCreationForm called." << RESET << std::endl;
}

const char* ShrubberyCreationForm::FileCreateException::what() const throw(){
	return ("Failed to create output file.");
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const{
	std::ofstream	ofs;
	std::string		file;

	this->checkRequirements(executor);
	
	file = this->_target + "_shrubbery";
	ofs.open(file.c_str());
	if (ofs.fail()){
		throw ShrubberyCreationForm::FileCreateException();
	}
	ofs <<		"		               ,@@@@@@@,\n";
	ofs <<		"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	ofs <<		"    ,&/%/%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	ofs <<		"   ,%&/%&&%&&%,@@@/@@@/@@@88\\88888/88'\n";
	ofs <<		"   %&&%&%&/%&&%@@/@@/ /@@@88888\\88888'\n";
	ofs <<		"   %&&%/ %&/%/%&&@@/ V /@@' `88\\8 `/88'\n";
	ofs <<		"   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	ofs <<		"       |o|        | |         | |\n";
	ofs <<		"       |.|        | |         | |\n";
	ofs <<		"    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
	std::cout << "File " << file << " created." << std::endl;
	ofs.close();
}
