/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:48:37 by mababou           #+#    #+#             */
/*   Updated: 2022/04/05 16:37:15 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

int main(void)
{
	srand(time(NULL));
	std::cout << "\e[7m======================TEST 1======================\e[0m" << std::endl;
	{
		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\e[7m======================TEST 2======================\e[0m" << std::endl;
	{
		try
		{
			Span sp = Span(5);
			sp.addNumber(-2147483648);
			sp.addNumber(2147483647);
			
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\e[7m======================TEST 3======================\e[0m" << std::endl;
	{
		try
		{
			Span sp = Span(15000);
			sp.fillSpan(15000);
			
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\e[7m======================TEST 4======================\e[0m" << std::endl;
	{
		try
		{
			Span sp = Span(10);
			sp.fillSpan(11);
			
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\e[7m======================TEST 5======================\e[0m" << std::endl;
	{
		try
		{
			int arr[] = {1, 5, 8, 9, 10, 18, 20};
    		int n = sizeof(arr) / sizeof(arr[0]);
			
			std::vector<int>	input(arr, arr + n);
			
			Span sp = Span(10);
			sp.fillSpan< std::vector<int> >(input.begin(), input.end());
			
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}