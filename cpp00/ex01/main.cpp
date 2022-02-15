/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:08:29 by mababou           #+#    #+#             */
/*   Updated: 2022/02/15 15:02:45 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <stdlib.h>

int main(void)
{
	PhoneBook phonebook;
	
	std::cout << "Welcome to Phonebook!" << std::endl;

	while (1)
	{
		std::string input;
		
		std::cout << "\033[0;32mPlease enter one of the following commands: ADD, SEARCH, EXIT\e[0m" << std::endl;
		std::cin >> input;
		if (input.compare("ADD") && input.compare("SEARCH") && input.compare("EXIT"))
		{
			std::cout << "Wrong command. Try again!" << std::endl;
			continue ;
		}
		if (!input.compare("ADD"))
			phonebook.add();
		if (!input.compare("SEARCH"))
			phonebook.search();
		if (!input.compare("EXIT"))
			return (0);
	}
}
