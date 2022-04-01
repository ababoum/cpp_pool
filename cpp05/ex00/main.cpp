/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:55:33 by mababou           #+#    #+#             */
/*   Updated: 2022/04/01 18:31:28 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat anonyme;
			Bureaucrat jacob("Jacob");
			Bureaucrat robert("Robert", 140);
			Bureaucrat robert2(robert);

			std::cout << jacob << std::endl;
			std::cout << robert << std::endl;
			std::cout << robert2 << std::endl;

			std::cout << "Grade decrement..." << std::endl;
			for (int i = 0; i < 9; i++)
				robert.gradeDecrement();
			std::cout << robert << std::endl;
			
			std::cout << "Grade increment..." << std::endl;
			for (int i = 0; i < 139; i++)
				robert2.gradeIncrement();
			std::cout << robert2 << std::endl;
					
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
			Bureaucrat albert("Albert", 151);					
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
			Bureaucrat albert("Albert", 0);					
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
			Bureaucrat albert("Albert", 10);
			for (int i = 0; i < 100; i++)
				albert.gradeIncrement();			
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
			Bureaucrat albert("Albert", 10);
			for (int i = 0; i < 200; i++)
				albert.gradeDecrement();			
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}