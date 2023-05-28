/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 01:42:57 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/28 19:10:40 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap( void );
		FragTrap(FragTrap const& copy);
		FragTrap(std::string const& name);
		~FragTrap( void );

		FragTrap& operator=(FragTrap const & src);

		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif
