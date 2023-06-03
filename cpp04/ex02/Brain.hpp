/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:40:32 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/29 00:41:06 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

#define CYN "\e[0;36m"
#define RESET "\e[0m"

class Brain {
	public:
		Brain( void );
		Brain(Brain const& copy);
		~Brain( void );

		Brain& operator=(Brain const & src);

	private:
		std::string	_ideas[100];
};

#endif