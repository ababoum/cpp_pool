/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:58:57 by mababou           #+#    #+#             */
/*   Updated: 2022/04/04 16:04:41 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"



int	main(void)
{
	{
		try
		{
			std::list<int> lst;

			lst.push_back(100);
			lst.push_back(50);
			lst.push_back(20);
			lst.push_back(10);
			lst.push_back(0);
			lst.push_back(-50);
			// 100, 50, 20, 10, 0, -50

			displayIterator(easyfind(lst, 50), lst.end());
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\e[7m=====================================\e[0m" << std::endl;
	{
		try
		{
			std::list<int> lst;

			lst.push_back(100);
			lst.push_back(50);
			lst.push_back(20);
			lst.push_back(10);
			lst.push_back(0);
			lst.push_back(-50);
			// 100, 50, 20, 10, 0, -50

			displayIterator(easyfind(lst, 550), lst.end());
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\e[7m=====================================\e[0m" << std::endl;
	{
		try
		{
			std::list<int> lst;

			lst.push_back(50);
			lst.push_back(50);
			lst.push_back(50);
			lst.push_back(50);
			lst.push_back(50);
			lst.push_back(50);
			// 50, 50, 50, 50, 50, 50

			displayIterator(easyfind(lst, 50), lst.end());
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\e[7m=====================================\e[0m" << std::endl;
	{
		try
		{
			std::vector<int> lst;

			for (int i = 0; i < 100; i += 10)
				lst.push_back(i);

			displayIterator(easyfind(lst, 50), lst.end());
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\e[7m=====================================\e[0m" << std::endl;
	{
		try
		{
			std::vector<int> lst;

			for (int i = 0; i < 100; i += 10)
				lst.push_back(i);

			displayIterator(easyfind(lst, 51), lst.end());
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\e[7m=====================================\e[0m" << std::endl;
	{
		try
		{
			std::deque<int> lst;

			for (int i = 0; i < 100; i += 10)
				lst.push_back(i);

			displayIterator(easyfind(lst, 40), lst.end());
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	return (0);
}