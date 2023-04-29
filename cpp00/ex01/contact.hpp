/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:16:53 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/29 15:48:11 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string> /*std::string*/

class Contact{

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phone;
	std::string	_darkestSecret;

public:
	Contact( void ); //constructor
	~Contact( void ); //destructor
	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickname(void) const;
	std::string	getPhone(void) const;
	std::string	getSecret(void) const;
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setNickname(std::string nickname);
	void setPhone(std::string phoneNumber);
	void setSecret(std::string darkestSecret);
};

#endif
