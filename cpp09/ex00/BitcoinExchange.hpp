/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 23:27:14 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/30 23:11:40 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <map>

class BitcoinExchange {
	public:
		BitcoinExchange(void);
		BitcoinExchange(std::string inputFile);
		~BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const& copy);

		BitcoinExchange& operator=(BitcoinExchange const & src);
		
		void	initData(void);
	private:
		std::string	_inputFile;
		std::string	_dataFile;
		std::map<std::string, float>	_dataBase;

		void	_initDataFile();
		void	_initInputFile();
		void	_calcBitcoin(std::string date, float value);
		float	_calcValue(std::string date, float value);
		int		_validDate(std::string strDate);
		int		_checkYear(int year, int month, int day);
		int		_checkMonth(int month);
		int		_checkDay(int year, int month, int day);
		bool	_isLeap(int year);
};

#endif
