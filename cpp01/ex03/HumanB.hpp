/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:08:45 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 15:58:44 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

#define RESET "\e[0m"
#define BHGRN "\e[1;92m"

class HumanB {
	private:
		Weapon*		_weapon;
		std::string	_name;

	public:
		void	attack(void);
		void	setWeapon(Weapon& weapon);
		HumanB(std::string name);
		~HumanB( void );
};

#endif
