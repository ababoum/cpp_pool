/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:55:33 by mababou           #+#    #+#             */
/*   Updated: 2022/04/01 19:01:31 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int	main(void)
{
	
	{
		try
		{
			Bureaucrat gerard("Gerard", 1);

			std::cout << gerard << std::endl;

			ShrubberyCreationForm	tree("Claude");
			
			tree.beSigned(gerard);
			std::cout << tree << std::endl;
			gerard.executeForm(tree);
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
			Bureaucrat gerard("Gerard", 145);

			std::cout << gerard << std::endl;

			ShrubberyCreationForm	tree("Claude");
			
			tree.beSigned(gerard);
			std::cout << tree << std::endl;
			gerard.executeForm(tree);
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
			Bureaucrat	robert("Robert", 10);
			
			std::cout << robert << std::endl;
			
			RobotomyRequestForm		robot("Bob");

			robot.beSigned(robert);
			std::cout << robot << std::endl;
			robert.executeForm(robot);	
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
			Bureaucrat	ministre("Ministre", 25);
			Bureaucrat	president("President", 25);

			for (int i = 0; i < 20; i++)
				president.gradeIncrement();
			
			std::cout << ministre << std::endl;
			std::cout << president << std::endl;
			
			PresidentialPardonForm		f1("Trump");
			f1.beSigned(ministre);			
			PresidentialPardonForm		f2(f1);

			std::cout << f1 << std::endl;
			std::cout << f2 << std::endl;
			
			ministre.executeForm(f2);	
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
			Bureaucrat	ministre("Ministre", 25);
			Bureaucrat	president("President", 25);

			for (int i = 0; i < 20; i++)
				president.gradeIncrement();
			
			std::cout << ministre << std::endl;
			std::cout << president << std::endl;
			
			PresidentialPardonForm		f1("Trump");
			f1.beSigned(ministre);			
			PresidentialPardonForm		f2(f1);

			std::cout << f1 << std::endl;
			std::cout << f2 << std::endl;
			
			president.executeForm(f2);	
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}