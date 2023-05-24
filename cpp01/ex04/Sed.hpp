/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:13:40 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/24 11:34:22 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <string>
#include <iostream>
#include <fstream> /*ifs*/
#include <sstream> /*stringstream*/

#define RED "\e[0;31m"
#define RESET "\e[0m"

#define WRONG_ARG "Invalid number of arguments. Use: ./sed <filename> <s1> <s2>"
#define FILE "Could not open the file. Check that the file exists and that the name is correct."
#define EMPTY "Empty file."
#define EMPTYSTR "Nothing to replace. S1 or s2 is empty."

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
