/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:40:32 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/29 00:41:06 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << CYN << "Default constructor Brain called." << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "what's your idea?";
	return;
}

Brain::Brain(Brain const& copy) {
	std::cout << CYN << "Copy constructor Brain called." << RESET << std::endl;
	*this = copy;
}

Brain::~Brain(void){
	std::cout << CYN << "Destructor Brain called." << RESET << std::endl;
	return;
}

Brain& Brain::operator=(Brain const & src){
	if (this != &src){
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	std::cout << CYN << "Copy assignment Brain operator called." << RESET << std::endl;
	return (*this);
}

std::string	Brain::getIdeas(int i) const {
	if (i >= 0 && i < 100)
		return(_ideas[i]);
	return (NULL);
}

void	Brain::setIdeas(int i, std::string idea) {
	if (i >= 0 && i < 100) {
        _ideas[i] = idea;
    }
}