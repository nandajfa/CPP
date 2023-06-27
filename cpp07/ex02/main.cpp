/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 01:59:02 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/20 21:10:42 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	try {
		std::cout << CYN << "Test default constructor" << RESET << std::endl;
		Array<int>	arr1;
		std::cout << "arr1<int> size: " << arr1.size() << std::endl;
		std::cout << std::endl;

		std::cout << CYN << "Test parameter constructor" << RESET << std::endl;
		Array<int>	arr2(8);
		std::cout << "arr2<int> size: " << arr2.size() << std::endl;
		for (unsigned int i = 0; i < arr2.size(); i++)
			std::cout << arr2[i] << " | ";
		std::cout << std::endl;
		std::cout << std::endl;
		
		std::cout << CYN << "Test copy constructor: copy of arr2" << RESET << std::endl;
		Array<int> arr3(arr2);
		arr3[0] = 10;
		std::cout << "arr3<int> size: " << arr3.size() << std::endl;
		for (unsigned int i = 0; i < arr2.size(); i++)
			std::cout << arr3[i] << " | ";
		std::cout << std::endl;
		std::cout << std::endl;
		
		std::cout << CYN << "Test operator '=' " << RESET << std::endl;
		Array<char> arrCh(6);
		std::cout << "arrCh<char> size: " << arrCh.size();
		for (unsigned int i = 0; i < arrCh.size(); ++i){
        	arrCh[i] = 'A' + i;
		}
		std::cout << std::endl;
		
		Array<char>	arrCh1 = arrCh;
		std::cout << "arrCh1<char> size: " << arrCh1.size() << std::endl;
		for (unsigned int i = 0; i < arrCh1.size(); ++i){
        	arrCh1[i] = 'A' + i;
		}
		arrCh[0] = 'm';
		arrCh1[4] = 'P';
		std::cout << std::endl;
		
		std::cout << "Array char 'arrCh'" << std::endl;
		for (unsigned int i = 0; i < arrCh.size(); i++)
			std::cout << arrCh[i] << " | ";
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Array char 'arrCh1' : copy of 'arrCh'" << std::endl;
		for (unsigned int i = 0; i < arrCh1.size(); i++)
			std::cout << arrCh1[i] << " | ";
		std::cout << std::endl;
		std::cout << std::endl;
		
		std::cout << CYN << "String array" << RESET << std::endl;
		Array<std::string>	str_array(4);
		str_array[0] = "Don't";
		str_array[1] = "give";
		str_array[2] = "up";
		str_array[3] = "!";
		for (unsigned int i = 0; i < str_array.size(); i++)
			std::cout << str_array[i] << " ";
		std::cout << std::endl;
		str_array[0] = "Yes,";
		for (unsigned int i = 0; i < str_array.size(); i++)
			std::cout << str_array[i] << " ";
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Accessing str_array[8]: ";
        std::cout << str_array[8] << std::endl;
	} catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
    return 0;
}