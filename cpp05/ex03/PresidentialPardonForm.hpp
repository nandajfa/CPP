/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:03:31 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/20 16:11:43 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const& copy);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm(void);

		PresidentialPardonForm& operator=(PresidentialPardonForm const & src);

		void	execute(const Bureaucrat& executor) const;
	private:
		std::string	_target;
};

#endif
