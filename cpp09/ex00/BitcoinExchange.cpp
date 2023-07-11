/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 23:27:08 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/30 22:48:09 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) :
	_inputFile("input.txt"),
	_dataFile("data.csv") {
}

BitcoinExchange::BitcoinExchange(std::string inputFile) : 
	_inputFile(inputFile),
	_dataFile("data.csv") {
}

BitcoinExchange::~BitcoinExchange(void){
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& copy){
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & src){
	if (this != &src){
		this->_inputFile = src._inputFile;
		this->_dataFile = src._dataFile;
	}
	return (*this);
}

void	BitcoinExchange::initData(){
	_initDataFile();
	_initInputFile();
}

void	BitcoinExchange::_initDataFile(){
	std::ifstream	ifs;
	std::string		date, value, line;

	ifs.open(this->_dataFile.c_str());
	if (ifs.fail())
		throw std::runtime_error("Could not open file: 'data.csv'.");
	std::getline(ifs, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Invalid format header.");
	while (std::getline(ifs, line)){
		size_t pos = line.find(',');
		
		date = line.substr(0, pos);
		value = line.substr(pos + 1);
		float rate = atof(value.c_str());
		_dataBase[date] = rate;
    }
	ifs.close();
}

void	BitcoinExchange::_initInputFile(){
	std::ifstream	ifs;
	std::string		line, date, value;

	ifs.open(this->_inputFile.c_str());
	std::getline(ifs, line);
	if (line != "date | value")
		throw std::runtime_error("Invalid format header.");
	while (std::getline(ifs, line)){
		if (line.find("|") == std::string::npos || line.empty())
			std::cout << "Error: bad input => " << line << std::endl;
		else
		{
			size_t pos = line.find('|');
			date = line.substr(0, pos);
			value = line.substr(pos + 1);
			float rate = atof(value.c_str());
			_calcBitcoin(date, rate);
		}
	}
}

void	BitcoinExchange::_calcBitcoin(std::string date, float value){
	if (_validDate(date)){
		std::cout << "Error: Invalid date." << std::endl;
		return ;
	}
	if (value < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else if (value > 1000)
		std::cout << "Error: too large a number." << std::endl;
	else {
		float result = _calcValue(date, value);
		std::cout << date << "=> " << value << " = " << result << std::endl;
	}
}

float	BitcoinExchange::_calcValue(std::string date, float value){
	std::map<std::string, float>::iterator	it;
	it = _dataBase.find(date);
	if (it != _dataBase.end())
		return (it->second * value);
	for (it = _dataBase.begin(); it != _dataBase.end(); it++){
		std::map<std::string, float>::iterator	next = it;
		next++;
		if (((date >= it->first) && (next == _dataBase.end()))
			|| ((date >= it->first) && (date < next->first)))
			return (it->second * value);
	}
	return (0);
}

int	BitcoinExchange::_validDate(std::string strDate){
	std::stringstream ss(strDate);
	char	delimiter;
	int		year, month, day;

	if (strDate.length() != 11)
		return (1);
	if (!(ss >> year >> delimiter >> month >> delimiter >> day))
		return (1);
	if (_checkYear(year, month, day) || _checkMonth(month)
		|| _checkDay(year, month, day))
		return (1);
	return (0);
}

int	BitcoinExchange::_checkYear(int year, int month, int day){
	if (year < 2009 || year > 2023)
		return (1);
	if (year == 2009 && month == 01 && day == 01)
		return (1);
	return (0);
}

int	BitcoinExchange::_checkMonth(int month){
	if (month < 1 || month > 12)
		return (1);
	return (0);
}

int	BitcoinExchange::_checkDay(int year, int month, int day){
	int maxDay = 31;

	if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
		maxDay = 30;
	else if (month == 02)
		maxDay = _isLeap(year) ? 29 : 28;
	if (day > maxDay)
		return (1);
	return (0);
}

bool	BitcoinExchange::_isLeap(int year){
	return ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)));
}
