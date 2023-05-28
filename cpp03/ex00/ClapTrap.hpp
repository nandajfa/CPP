/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:22:37 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/28 19:06:23 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

#define GRN "\e[0;32m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define BWHT "\e[1;37m"
#define RESET "\e[0m"

class ClapTrap {
	public:
		ClapTrap( void );
		ClapTrap(ClapTrap const& copy);
		ClapTrap(std::string const& name);
		~ClapTrap( void );

		ClapTrap& operator=(ClapTrap const & src);

		std::string getName( void ) const;
		int getHitPoints( void ) const;
		int getEnergyPoints( void ) const;
		int getAttackDamage( void ) const;

		void setName( std::string const &name );
		void setHitPoints( int hitPoints );
		void setEnergyPoints( int energy );
		void setAttackDamage( int attack );

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

#endif
