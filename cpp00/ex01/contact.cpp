/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:42:17 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 15:48:26 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() {
	return;
}

Contact::~Contact() {
	return;
}

std::string Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string Contact::getNickname(void) const
{
	return (this->_nickname);
}

std::string Contact::getPhone(void) const
{
	return (this->_phone);
}

std::string Contact::getSecret(void) const
{
	return (this->_darkestSecret);
}

void	Contact::setFirstName(std::string firstName){
	this->_firstName = firstName;
}

void	Contact::setLastName(std::string lastName){
	this->_lastName = lastName;
}

void	Contact::setNickname(std::string nickname){
	this->_nickname = nickname;
}

void	Contact::setPhone(std::string phoneNumber){
	this->_phone = phoneNumber;
}

void	Contact::setSecret(std::string darkestSecret){
	this->_darkestSecret = darkestSecret;
}
