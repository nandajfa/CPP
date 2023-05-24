/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:14:16 by jefernan          #+#    #+#             */
/*   Updated: 2023/05/24 11:34:12 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string fileName, std::string s1, std::string s2){
	this->_fileName = fileName;
	this->_s1 = s1;
	this->_s2 = s2;
}
Sed::~Sed(){
	return;
}

int	Sed::openFile(void)
{
	std::ifstream	ifs;
	std::stringstream ss;
	std::string		str;

	ifs.open(this->_fileName.c_str());
	ss << ifs.rdbuf();
	str = ss.str();
	this->_content = this->_replace(str);
	this->_write();
	ifs.close();
	return (0);
}

std::string	Sed::_replace(std::string content)
{
	size_t pos;

	pos = content.find(this->_s1);
	if (pos == std::string::npos){
		std::cout << RED << "s1 not found. Nothing will be replaced." << RESET << std::endl;
		return (content);
	}
	while (pos != std::string::npos) {
    	content = content.substr(0, pos) +  "|" + this->_s2 + "|"
			+ content.substr(pos + this->_s1.length());
		pos = content.find(this->_s1, pos + this->_s2.length() + 2);
	}
	return (content);
}

void	Sed::_write(void)
{
	std::ofstream	ofs;
	std::string		fileOut;

	fileOut = this->_fileName + ".replace";
	ofs.open(fileOut.c_str());
	if (ofs.fail()){
		std::cerr << "error creating file" << std::endl;
		exit (1);
	}
	ofs << this->_content;
	ofs.close();
}
