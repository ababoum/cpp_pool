/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:55:33 by mababou           #+#    #+#             */
/*   Updated: 2022/04/01 18:49:10 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat robert("Robert", 140);

			std::cout << robert << std::endl;

			Form	cerfa1522("Cerfa 1522", 150, 150);

			cerfa1522.beSigned(robert);

			std::cout << cerfa1522 << std::endl;
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
			Bureaucrat robert("Robert", 140);

			std::cout << robert << std::endl;

			Form	cerfa1522("Cerfa 1522", 151, 150);

			cerfa1522.beSigned(robert);

			std::cout << cerfa1522 << std::endl;					
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
			Bureaucrat robert("Robert", 140);

			std::cout << robert << std::endl;

			Form	cerfa1522("Cerfa 1522", 15, 15);

			cerfa1522.beSigned(robert);

			std::cout << cerfa1522 << std::endl;					
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
			Bureaucrat robert("Robert", 10);

			std::cout << robert << std::endl;

			Form	cerfa1522("Cerfa 1522", 150, 0);

			cerfa1522.beSigned(robert);

			std::cout << cerfa1522 << std::endl;					
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}