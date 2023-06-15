/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:11:00 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/15 20:18:24 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2){
		std::cout << "Wrong number of arguments. Use: ./converter [value]." << std::endl;
		return (0);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}