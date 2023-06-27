/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:40:32 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/19 20:58:53 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include <iostream>

#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define RESET "\e[0m"

class AAnimal {
	public:
		AAnimal( void );
		AAnimal(AAnimal const& copy);
		virtual ~AAnimal( void );

		AAnimal& operator=(AAnimal const & src);

		std::string		getType(void) const;
		void			setType(std::string type);
		virtual void	makeSound(void) const = 0;
	protected:
		std::string _type;
};

#endif