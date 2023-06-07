/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 02:23:42 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/04 01:35:02 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm(void);
		AForm(AForm const& copy);
		AForm(std::string name, int gradeSign, int gradeEx);
		virtual ~AForm(void);
		
		AForm& operator=(AForm const & src);

		std::string getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToEx(void) const;
		
		void			beSigned(const Bureaucrat& br);
		virtual void	execute(Bureaucrat const & executor) const = 0;
		void			checkRequirements(Bureaucrat const & br) const;

		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};

		class IsNotSignedException : public std::exception {
			virtual const char* what() const throw();
		};
		
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToEx;	
};

std::ostream& operator<<(std::ostream& os, const AForm& fr);

#endif