/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:58:57 by mababou           #+#    #+#             */
/*   Updated: 2022/04/04 13:45:25 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750

struct	Data {
	int			int_val;
	std::string	str_val;
};

int main(void)
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
			for (unsigned int i = 0; i < lst.size(); i++)
			{
				lst[i] = i * i;
				std::cout << i << ": " << lst[i] << std::endl;
			}
		}
		catch (std::exception &e)
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
			for (unsigned int i = 0; i < lst.size(); i++)
			{
				lst[i] = i * i;
				std::cout << i << ": " << lst[i] << std::endl;
			}
		}
		catch (std::exception &e)
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
			for (unsigned int i = 0; i < lst.size(); i++)
			{
				lst[i] = "salut";
				std::cout << i << ": " << lst[i] << std::endl;
			}
			std::cout << "Showing the copied list:" << std::endl;
			for (unsigned int i = 0; i < lst2.size(); i++)
			{
				std::cout << i << ": " << lst2[i] << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\e[7m=====================================\e[0m" << std::endl;
	{
		try
		{
			Array<Data> lst(5);
			std::cout << "List size: " << lst.size() << std::endl;
			std::cout << "Default initialization:" << std::endl;
			for (unsigned int i = 0; i < lst.size(); i++) {
				std::cout << i << ": " << lst[i].int_val << std::endl;
				std::cout << i << ": " << lst[i].str_val << std::endl;
			}
			std::cout << "Transforming the list:" << std::endl;
			for (unsigned int i = 0; i < lst.size(); i++)
			{
				lst[i].int_val = i * i;
				lst[i].str_val += static_cast<char>('a' + i);
				std::cout << i << ": " << lst[i].int_val << std::endl;
				std::cout << i << ": " << lst[i].str_val << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\e[7m=====================================\e[0m" << std::endl;
	{
		Array<int> numbers(MAX_VAL);
		int *mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
	
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);

			std::cout << "Copy test:" << std::endl;
			std::cout << tmp[100] << " vs " << test[100] << std::endl;
			std::cout << tmp[250] << " vs " << test[250] << std::endl;		
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "Mirror test before update:" << std::endl;
		std::cout << numbers[250] << " vs " << mirror[250] << std::endl;
		std::cout << numbers[100] << " vs " << mirror[100] << std::endl;
		std::cout << numbers[13] << " vs " << mirror[13] << std::endl;

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}

		std::cout << "Mirror test after updating original array:" << std::endl;
		std::cout << numbers[250] << " vs " << mirror[250] << std::endl;
		std::cout << numbers[100] << " vs " << mirror[100] << std::endl;
		std::cout << numbers[13] << " vs " << mirror[13] << std::endl;

		delete[] mirror;
	}

	return (0);
}