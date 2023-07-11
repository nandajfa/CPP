/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:47:21 by jefernan          #+#    #+#             */
/*   Updated: 2023/07/10 15:56:39 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	if (argc < 2){
		std::cerr << "Wrong number of arguments." << std::endl;
		return (1);
	}
	try {
		PmergeMe pm;
		pm.pMerge(argc, argv);
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}

}