/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 23:27:17 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/30 22:24:16 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	checkFile(const std::string& fileName) {
    std::ifstream file;
    file.open(fileName.c_str());
	if (file.fail()){
		std::cerr << "Error: could not open file." << std::endl;
		file.close();
		return (true);
	}
	if (file.peek() == EOF){
		std::cerr << "Error: empty file." << std::endl;
		file.close();
		return (true);
	}
	file.close();
	return (false);
}

int	main(int argc, char *argv[])
{
	if (argc != 2){
		std::cerr << "Wrong number of arguments. Usage: ./btc <file>" << std::endl;
		return (1);
	}
	if (checkFile(argv[1]))
		return (1);
	try {
		BitcoinExchange	btc(argv[1]);
		btc.initData();
	}
	catch (std::exception const &e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}