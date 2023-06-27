/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:40:32 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/19 20:59:24 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define RESET "\e[0m"

class Animal {
	public:
		Animal( void );
		Animal(Animal const& copy);
		virtual ~Animal( void );

		Animal& operator=(Animal const & src);

		std::string		getType(void) const;
		void			setType(std::string type);
		virtual void	makeSound(void) const;
	protected:
		std::string _type;
};

#endif
