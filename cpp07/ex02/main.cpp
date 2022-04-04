/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:58:57 by mababou           #+#    #+#             */
/*   Updated: 2022/04/04 12:13:52 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	{
		try
		{
			Array<int> lst(5);
			std::cout << "List size: " << lst.size() << std::endl;
			std::cout << "Default initialization:" << std::endl;
			for (unsigned int i = 0; i < lst.size(); i++)
				std::cout << i << ": " << lst[i] << std::endl;
			std::cout << "Transforming the list:" << std::endl;
			for (unsigned int i = 0; i < lst.size(); i++) {
				lst[i] = i * i;
				std::cout << i << ": " << lst[i] << std::endl;
			}
		}
		catch (Array<int>::OutOfRangeException e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\e[7m=====================================\e[0m" << std::endl;
	{
		try
		{
			Array<int> lst(5);
			std::cout << "List size: " << lst.size() << std::endl;
			std::cout << "Default initialization:" << std::endl;
			for (unsigned int i = 0; i < lst.size() + 1; i++)
				std::cout << i << ": " << lst[i] << std::endl;
			std::cout << "Transforming the list:" << std::endl;
			for (unsigned int i = 0; i < lst.size(); i++) {
				lst[i] = i * i;
				std::cout << i << ": " << lst[i] << std::endl;
			}
		}
		catch (Array<int>::OutOfRangeException e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\e[7m=====================================\e[0m" << std::endl;
	{
		try
		{
			Array<std::string> lst(5);
			std::cout << "List size: " << lst.size() << std::endl;
			std::cout << "Default initialization:" << std::endl;
			for (unsigned int i = 0; i < lst.size(); i++)
				std::cout << i << ": " << lst[i] << std::endl;
			std::cout << "List copy" << std::endl;
			
			Array<std::string> lst2(lst);
			std::cout << "Transforming the original list:" << std::endl;
			for (unsigned int i = 0; i < lst.size(); i++) {
				lst[i] = "salut";
				std::cout << i << ": " << lst[i] << std::endl;
			}
			std::cout << "Showing the copied list:" << std::endl;
			for (unsigned int i = 0; i < lst2.size(); i++) {
				std::cout << i << ": " << lst2[i] << std::endl;
			}
		}
		catch (Array<int>::OutOfRangeException e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\e[7m=====================================\e[0m" << std::endl;
	{
		try
		{
			Array<std::string> lst(-5);
			std::cout << "List size: " << lst.size() << std::endl;
			std::cout << "Default initialization:" << std::endl;
			for (unsigned int i = 0; i < lst.size(); i++)
				std::cout << i << ": " << lst[i] << std::endl;
			std::cout << "List copy" << std::endl;
			
			Array<std::string> lst2(lst);
			std::cout << "Transforming the original list:" << std::endl;
			for (unsigned int i = 0; i < lst.size(); i++) {
				lst[i] = "salut";
				std::cout << i << ": " << lst[i] << std::endl;
			}
			std::cout << "Showing the copied list:" << std::endl;
			for (unsigned int i = 0; i < lst2.size(); i++) {
				std::cout << i << ": " << lst2[i] << std::endl;
			}
		}
		catch (Array<int>::OutOfRangeException e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	return (0);
}