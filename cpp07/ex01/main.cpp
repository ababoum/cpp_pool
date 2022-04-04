/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:26:04 by mababou           #+#    #+#             */
/*   Updated: 2022/04/04 11:57:09 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "iter.hpp"
# include "Awesome.hpp"

void	putnbr(const int & nb) {
	std::cout << nb << std::endl;
};
	
void	putstr(const std::string & str) {
	std::cout << str << std::endl;
};

void	putfloat6(const float & nb) {
	std::cout << std::fixed << std::setprecision(6) << nb << std::endl;
};

void	putfloat1(const float & nb) {
	std::cout << std::fixed << std::setprecision(1) << nb  << std::endl;
};

int	main(void)
{
	{
		int lst_int[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		::iter(lst_int, 10, putnbr);
	}
	std::cout << "\e[7m=====================================\e[0m" << std::endl;
	{	
		std::string lst_str[5] = {"one", "two", "three", "four", "five"};
		::iter(lst_str, 5, putstr);
	}
	std::cout << "\e[7m=====================================\e[0m" << std::endl;
	{	
		float lst_float[5] = {1.2f, 5, 42.005f, 2147483647.5f, 0};
		::iter(lst_float, 5, putfloat6);
	}
	std::cout << "\e[7m=====================================\e[0m" << std::endl;
	{	
		float lst_float[5] = {1.2f, 5, 42.005f, 2147483647.5f, 0};
		::iter(lst_float, 5, putfloat1);
	}
	std::cout << "\e[7m=====================================\e[0m" << std::endl;
	{	
		int tab[] = { 0, 1, 2, 3, 4 };
		Awesome tab2[5];

		iter( tab, 5, print );
		iter( tab2, 5, print );
	}
	return (0);
}