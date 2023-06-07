/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 02:45:52 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/07 02:47:18 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const& copy);
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm(void);

		ShrubberyCreationForm& operator=(ShrubberyCreationForm const & src);

		void	execute(const Bureaucrat& executor) const;

		class FileCreateException : public std::exception {
			virtual const char* what() const throw();
		};
		
	private:
		std::string	_target;
};

#endif
