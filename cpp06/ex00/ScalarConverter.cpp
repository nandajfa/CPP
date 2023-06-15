/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:11:06 by jefernan          #+#    #+#             */
/*   Updated: 2023/06/15 22:38:31 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string ScalarConverter::_value = "";
char		ScalarConverter::_char = 0;
int			ScalarConverter::_int = 0;
double		ScalarConverter::_double = 0;
float		ScalarConverter::_float = 0;

ScalarConverter::ScalarConverter(void){
	_value = "";
	_char = 0;
	_int = 0;
	_double = 0;
	_float = 0;
}

ScalarConverter::~ScalarConverter(void){
	return;
}

ScalarConverter::ScalarConverter(ScalarConverter const& copy){
	*this = copy;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src){
	if (this != &src){
		this->setValue(src.getValue());
		this->_char = src._char;
		this->_int = src._int;
		this->_double = src._double;
		this->_float = src._float;
	}
	return (*this);
}

void	ScalarConverter::setValue(std::string const value) {
	_value = value;
}

std::string	ScalarConverter::getValue(void) {
	return (_value);
}

void	ScalarConverter::convert(const std::string& literal){
	setValue(literal);
	if (_isChar(literal))
		_printOnlyChar(literal);
	else if (_isInt(literal) || _isFloat(literal) || _isDouble(literal))
		_print();
	else if (_isPseudo(literal) != -1)
		_printPseudo(literal);
	else
		_impossible();
}

bool	ScalarConverter::_isChar(const std::string& value){
	if (value.size() == 1 && !std::isdigit(value[0])){
		return (true);
	}
	return (false);
}

bool	ScalarConverter::_isInt(const std::string& value){
	for (size_t i = 0; i < value.length(); i++){
		if ((i == 0 && value[i] == '-') || value[i] == '+')
			continue ;
		if (!std::isdigit(value[i]))
			return (false);
	}
	return (true);
}

bool	ScalarConverter::_isFloat(const std::string& value){
	if (_isPseudo(_value) == _PSEUDO_FLOAT){
		return (false);
	}
	for (size_t i = 0; i < value.length(); i++){
		if ((i == 0 && value[i] == '-') || value[i] == '+')
			continue ;
		if (!std::isdigit(value[i]) && value[i] != '.' && value[i] != 'f')
			return (false);
		if (value[value.length() - 1] != 'f')
			return (false);
	}
	return (true);
}

bool	ScalarConverter::_isDouble(const std::string& value){
	if (value.find('.') == std::string::npos)
        return (false);
	if (_isPseudo(_value) == _PSEUDO_DOUBLE){
		return (false);
	}
	for (size_t i = 0; i < value.length(); i++){
		if ((i == 0 && value[i] == '-') || value[i] == '+')
			continue ;
		if (!std::isdigit(value[i]) && value[i] != '.') 
			return (false);
	}
	return (true);
}

int	ScalarConverter::_isPseudo(std::string value){
	std::string	pseudoDouble[4] = {"inf", "+inf", "-inf", "nan"};
	std::string	pseudoFloat[4] = {"inff", "+inff", "-inff", "nanf"};
	for (int i = 0; i < 4; i++){
		if (!pseudoDouble[i].compare(value))
			return (_PSEUDO_DOUBLE);
		if (!pseudoFloat[i].compare(value))
			return (_PSEUDO_FLOAT);
	}
	return (-1);
}

void	ScalarConverter::_printOnlyChar(std::string const& value){
	if (isprint(value[0]))
		std::cout << "char:   '" << value << "'" << std::endl;
	else
		std::cout << "char: Non displayable." << std::endl;
	std::cout.precision(1);
	std::cout << "int:    " << static_cast<int>(value[0]) << std::endl;
	std::cout << "float:  " << std::fixed << static_cast<float>(value[0]) << "f" << std::endl;
	std::cout << "double: " << std::fixed << static_cast<double>(value[0]) << std::endl;
		
}

void	ScalarConverter::_print(void){
	std::stringstream ss;
    long double       literal;
	
	ss << _value;
	ss >> literal;
	ScalarConverter::_printChar(literal);
	ScalarConverter::_printInt(literal);
	ScalarConverter::_printFloat(literal);
	ScalarConverter::_printDouble(literal);
	std::cout << std::endl;
}

void	ScalarConverter::_printChar(long double& value){
	_char = static_cast<char>(value);
	
	if (value > CHAR_MAX || value < CHAR_MIN)
		std::cout << "char: impossible." << std::endl;	
	else if (isprint(_char))
		std::cout << "char: '" << _char << "'" << std::endl;
	else
		std::cout << "char: Non displayable." << std::endl;
}

void	ScalarConverter::_printInt(long double& value){
	_int = static_cast<int>(atoi(_value.c_str()));
	
	if (value > INT_MAX || value < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << _int << std::endl;
}

void	ScalarConverter::_printFloat(long double& value){
	_float = static_cast<float>(atof(_value.c_str()));
	
	std::cout.precision(1);
	if (value > FLT_MAX || value < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << _float << "f" << std::endl;
}

void	ScalarConverter::_printDouble(long double& value){
	_double = static_cast<double>(strtod(_value.c_str(), NULL));
	
	std::cout.precision(1);
	if (value > DBL_MAX || value < -DBL_MAX)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << _double  << std::endl;
}

void	ScalarConverter::_printPseudo(std::string value){
	if (_isPseudo(value) == _PSEUDO_DOUBLE){
		std::cout << "char:   impossible" << std::endl;
        std::cout << "int:    impossible" << std::endl;
        std::cout << "float:  " << value << "f" << std::endl;
        std::cout << "double: " << value << std::endl;
	}
	if (_isPseudo(value) == _PSEUDO_FLOAT){
		std::cout << "char:   impossible" << std::endl;
        std::cout << "int:    impossible" << std::endl;
        std::cout << "float:  " << value << std::endl;
        std::cout << "double: " << value.substr(0, (value.size() - 1)) << std::endl;
	}
}

void	ScalarConverter::_impossible(void){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
}
