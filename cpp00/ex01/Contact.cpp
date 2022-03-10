/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:44:43 by mababou           #+#    #+#             */
/*   Updated: 2022/03/10 16:20:01 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::setFirstName(std::string first_name)
{
	this->_first_name = first_name;
}

void	Contact::setLastName(std::string last_name)
{
	this->_last_name = last_name;
}

void	Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phone_number)
{
	this->_phone_number = phone_number;
}

void	Contact::setDarkestSecret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

std::string	Contact::getFirstName(void)
{
	return (this->_first_name);
}

std::string	Contact::getLastName(void)
{
	return (this->_last_name);
}

std::string	Contact::getNickname(void)
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber(void)
{
	return (this->_phone_number);
}

std::string	Contact::getDarkestSecret(void)
{
	return (this->_darkest_secret);
}