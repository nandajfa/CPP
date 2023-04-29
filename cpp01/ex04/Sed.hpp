/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:13:40 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 18:16:33 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Sed {
	public:
	Sed(std::string fileName, std::string s1, std::string s2);
	~Sed( void );
	int			openFile(void);

	private:

	std::string	_s1;
	std::string	_s2;
	std::string	_fileName;
	std::string	_content;
	std::string	_replace(std::string content);
	void		_write(void);
};

#endif
