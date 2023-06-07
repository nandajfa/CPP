/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 23:13:27 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/07 20:15:28 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define RED "\e[0;31m"
#define RESET "\e[0m"

class AForm;

class Bureaucrat {
	public:
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(Bureaucrat const& copy);
		Bureaucrat(std::string name, int grade);

		Bureaucrat& operator=(Bureaucrat const& src);

		std::string	getName(void) const;
		int			getGrade(void) const;
		
		void 		increment(void);
		void 		decrement(void);
		void		signForm(AForm &form);
		void		executeForm(AForm const & form);

		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};

	private:
		std::string	_name;
		int			_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& br);

#endif