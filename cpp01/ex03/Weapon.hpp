/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:08:59 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 15:59:15 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {

private:
	std::string	_type;

public:
	Weapon(std::string type);
	~Weapon( void );
	std::string	getType(void);
	void		setType(std::string type);
};

#endif
