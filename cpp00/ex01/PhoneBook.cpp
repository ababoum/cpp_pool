/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:10:26 by mababou           #+#    #+#             */
/*   Updated: 2022/03/10 18:47:48 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _cursor(0), _size(0)
{
	std::cout << "A new phonebook is created." << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "The phonebook is destroyed." << std::endl;
	return ;
}

void	PhoneBook::add(void)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	while (first_name.empty())
	{
		std::cout << "\e[1mFirst name:\e[0m" << std::endl;
		std::getline(std::cin, first_name);
	}
	while (last_name.empty())
	{
		std::cout << "\e[1mLast name:\e[0m" << std::endl;
		std::getline(std::cin, last_name);
	}
	while (nickname.empty())
	{
		std::cout << "\e[1mNickname:\e[0m" << std::endl;
		std::getline(std::cin, nickname);
	}
	while (phone_number.empty())
	{
		std::cout << "\e[1mPhone number:\e[0m" << std::endl;
		std::getline(std::cin, phone_number);
	}
	while (darkest_secret.empty())
	{
		std::cout << "\e[1mDarkest secret:\e[0m" << std::endl;
		std::getline(std::cin, darkest_secret);
	}

	this->_contact_list[this->_cursor].setFirstName(first_name);
	this->_contact_list[this->_cursor].setLastName(last_name);
	this->_contact_list[this->_cursor].setNickname(nickname);
	this->_contact_list[this->_cursor].setPhoneNumber(phone_number);
	this->_contact_list[this->_cursor].setDarkestSecret(darkest_secret);

	std::cout << "Contact added in the slot " << this->_cursor << "." << std::endl;
	
	this->_cursor = (this->_cursor + 1) % 8;
	if (this->_size < 8)
		this->_size++;
	
	return ;
}

void	PhoneBook::_display_all(int index, Contact item) const
{
	std::cout << "         " << index << "|";

	if (item.getFirstName().length() > 10)
		std::cout << item.getFirstName().substr(0, 9) << "." << "|";
	else
	{
		int i = 11 - item.getFirstName().length();
		while (--i > 0)
			std::cout << " ";
		std::cout << item.getFirstName() << "|";
	}
	
	if (item.getLastName().length() > 10)
		std::cout << item.getLastName().substr(0, 9) << "." << "|";
	else
	{
		int i = 11 - item.getLastName().length();
		while (--i > 0)
			std::cout << " ";
		std::cout << item.getLastName() << "|";
	}

	if (item.getNickname().length() > 10)
		std::cout << item.getNickname().substr(0, 9) << "." << std::endl;
	else
	{
		int i = 11 - item.getNickname().length();
		while (--i > 0)
			std::cout << " ";
		std::cout << item.getNickname() << std::endl;
	}

	return ;
}

void	PhoneBook::_display(int index, Contact item) const
{
	std::cout << "\e[1mIndex: \e[0m" << index << std::endl;
	std::cout << "\e[1mFirst name: \e[0m"<< item.getFirstName() << std::endl;
	std::cout << "\e[1mLast name: \e[0m" << item.getLastName() << std::endl;
	std::cout << "\e[1mNickname: \e[0m"<< item.getNickname() << std::endl;
	std::cout << "\e[1mPhone number: \e[0m"<< item.getPhoneNumber() << std::endl;
	std::cout << "\e[1mDarkest secret: \e[0m"<< item.getDarkestSecret() << std::endl;

	return ;
}

void	PhoneBook::search(void) const
{
	std::string	input;
	int			index;

	index = 0;
	std::cout << "\e[1m     index|First name| Last name|  Nickname\e[0m" << std::endl;
	while (index < this->_size)
	{
		this->_display_all(index, this->_contact_list[index]);
		index++;
	}

	std::cout << "Enter the index of the contact to display:" << std::endl;
	std::getline(std::cin, input);
	index = atoi(input.data());
	if (index < 0 || index > this->_size - 1 || input.length() > 1 || !std::isdigit(input[0]))
		std::cout << "Invalid index." << std::endl;
	else
	{
		this->_display(index, this->_contact_list[index]);
	}
	return ;
}
