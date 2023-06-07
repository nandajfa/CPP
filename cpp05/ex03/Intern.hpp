/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 03:42:46 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/07 21:54:30 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define GRN "\e[0;32m"
#define BLU "\e[0;34m"
#define RED "\e[0;31m"
#define RESET "\e[0m"

class Intern {
	public:
		Intern(void);
		Intern(Intern const& copy);
		~Intern(void);

		Intern& operator=(Intern const& src);

		AForm* makeForm(std::string name, std::string target);

		class UnknownFormException : public std::exception {
			virtual const char* what() const throw();
		};
	private:
		AForm* _Shrubbery(std::string target);
		AForm* _Robotomy(std::string target);
		AForm* _Presidential(std::string target);
};

#endif