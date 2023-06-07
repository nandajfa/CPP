/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 02:23:42 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/04 01:35:02 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(void);
		Form(Form const& copy);
		Form(std::string name, int gradeSign, int gradeEx);
		~Form(void);
		
		Form& operator=(Form const & src);

		std::string getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToEx(void) const;
		
		void		beSigned(const Bureaucrat& br);

		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};
		
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToEx;	
};

std::ostream& operator<<(std::ostream& os, const Form& fr);

#endif