/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:10:26 by mababou           #+#    #+#             */
/*   Updated: 2022/02/15 13:18:21 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : cursor(0), size(0)
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

	this->contact_list[this->cursor].first_name = first_name;
	this->contact_list[this->cursor].last_name = last_name;
	this->contact_list[this->cursor].nickname = nickname;
	this->contact_list[this->cursor].phone_number = phone_number;
	this->contact_list[this->cursor].darkest_secret = darkest_secret;

	this->cursor = this->cursor + 1 % 8;
	if (this->size < 8)
		this->size++;
	
	return ;
}

void	PhoneBook::display(int index, Contact item)
{
		std::cout << "         " << index << "|";

		if (item.first_name.length() > 10)
			std::cout << item.first_name.substr(0, 9) << "." << "|";
		else
		{
			int i = 11 - item.first_name.length();
			while (--i > 0)
				std::cout << " ";
			std::cout << item.first_name << "|";
		}
		
		if (item.last_name.length() > 10)
			std::cout << item.last_name.substr(0, 9) << "." << "|";
		else
		{
			int i = 11 - item.last_name.length();
			while (--i > 0)
				std::cout << " ";
			std::cout << item.last_name << "|";
		}

		if (item.nickname.length() > 10)
			std::cout << item.nickname.substr(0, 9) << "." << std::endl;
		else
		{
			int i = 11 - item.nickname.length();
			while (--i > 0)
				std::cout << " ";
			std::cout << item.nickname << std::endl;
		}

		return ;
}

void	PhoneBook::search(void)
{
	int	index;

	std::cout << "Enter the index of the contact to display:" << std::endl;
	std::cin >> index;
	if (index < 0 || index > this->size - 1)
		std::cout << "Invalid index." << std::endl;
	else
	{
		this->display(index, this->contact_list[index]);
	}
	return ;
}
