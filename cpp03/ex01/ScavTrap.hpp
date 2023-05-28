/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:59:08 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/28 19:08:47 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap {
	public:
		ScavTrap( void );
		ScavTrap(ScavTrap const& copy);
		ScavTrap(std::string const& name);
		~ScavTrap( void );

		ScavTrap& operator=(ScavTrap const & src);

		void	attack(const std::string& target);
		void	guardGate( void );

};

#endif
