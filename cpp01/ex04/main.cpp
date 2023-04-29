/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:11:11 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 15:59:27 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4){
		std::cout << "Invalid number of arguments. Use: ./sed <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	Sed sed = Sed(argv[1], argv[2], argv[3]);
	sed.openFile();
	return (0);
}
