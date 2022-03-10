/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:10:26 by mababou           #+#    #+#             */
/*   Updated: 2022/03/10 16:23:32 by mababou          ###   ########.fr       */
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

	std::cout << "First name:" << std::endl;
	std::cin >> first_name;
	std::cout << "Last name:" << std::endl;
	std::cin >> last_name;
	std::cout << "Nickname:" << std::endl;
	std::cin >> nickname;
	std::cout << "Phone number:" << std::endl;
	std::cin >> phone_number;
	std::cout << "Darkest secret:" << std::endl;
	std::cin >> darkest_secret;

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

void	PhoneBook::_display(int index, Contact item) const
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

void	PhoneBook::search(void) const
{
	int	index;

	std::cout << "Enter the index of the contact to display:" << std::endl;
	std::cin >> index;
	if (index < 0 || index > this->_size - 1)
		std::cout << "Invalid index." << std::endl;
	else
	{
		this->_display(index, this->_contact_list[index]);
	}
	return ;
}
