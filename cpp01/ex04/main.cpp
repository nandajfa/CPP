/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:11:11 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/24 11:33:53 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

bool	isFileEmpty(const std::string& fileName) {
    std::ifstream file(fileName);
    return (file.peek() == EOF);
}

bool	printError(std::string msg){
	std::cerr << RED << msg << RESET << std::endl;
	return (false);
}

bool	handleErrors(int argc, char *argv[])
{
	std::ifstream	ifs;

	if (argc != 4)
		return (printError(WRONG_ARG));
	ifs.open(std::string(argv[1]).c_str());
	if (ifs.fail())
		return (printError(FILE));
	if (isFileEmpty(argv[1]))
		return (printError(EMPTY));
	if (std::string(argv[2]).size() == 0 || std::string(argv[3]).size() == 0)
		return (printError(EMPTYSTR));
	ifs.close();
	return (true);
}

int	main(int argc, char *argv[])
{
	if (handleErrors(argc, argv)){
		Sed sed = Sed(argv[1], argv[2], argv[3]);
		sed.openFile();
	}
	return (0);
}
