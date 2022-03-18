/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:55:33 by mababou           #+#    #+#             */
/*   Updated: 2022/03/18 13:36:24 by mababou          ###   ########.fr       */
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
		Bureaucrat albert("Albert", 151);
		Bureaucrat gerard("Gerard", -3);

		std::cout << robert << std::endl;
		std::cout << albert << std::endl;
		std::cout << gerard << std::endl;

		albert.gradeDecrement();
		albert.gradeDecrement();
		gerard.gradeIncrement();

		std::cout << robert << std::endl;
		std::cout << albert << std::endl;
		std::cout << gerard << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
	}	
	
	return (0);
}