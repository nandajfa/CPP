/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:08:41 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 15:58:24 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

#define HCYN "\e[0;96m"
#define RESET "\e[0m"

class HumanA {
	private:
		Weapon&	_weapon;
		std::string	_name;

	public:
		void attack(void);
		HumanA(std::string name, Weapon& weapon);
		~HumanA( void );
};

#endif
