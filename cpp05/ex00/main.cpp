/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:55:33 by mababou           #+#    #+#             */
/*   Updated: 2022/03/31 09:20:38 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat anonyme;
		Bureaucrat jacob("Jacob");
		Bureaucrat robert("Robert", 140);
		Bureaucrat robert2(robert);
		// Bureaucrat albert("Albert", 151);
		// Bureaucrat gerard("Gerard", -3);

		std::cout << jacob << std::endl;
		std::cout << robert << std::endl;
		std::cout << robert2 << std::endl;

		std::cout << "======================================" << std::endl;

		for (int i = 0; i < 9; i++)
			robert.gradeDecrement();
		std::cout << robert << std::endl;
		
		for (int i = 0; i < 140; i++)
			robert2.gradeIncrement();
		std::cout << robert2 << std::endl;
				
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}	
	return (0);
}