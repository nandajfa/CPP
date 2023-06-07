/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:03:40 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/07 01:13:01 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const& copy);
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm& operator=(RobotomyRequestForm const & src);

		void	execute(const Bureaucrat& executor) const;
	private:
		std::string	_target;
};

#endif