/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:33:58 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/29 00:40:30 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define RESET "\e[0m"

class WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(std::string const& type);
		WrongAnimal(WrongAnimal const& copy);
		virtual ~WrongAnimal(void);

		WrongAnimal& operator=(WrongAnimal const& src);

		std::string	getType(void) const;
		void		makeSound(void) const;

	protected:
		std::string _type;
};

#endif
