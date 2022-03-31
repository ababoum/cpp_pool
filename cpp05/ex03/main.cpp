/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:55:33 by mababou           #+#    #+#             */
/*   Updated: 2022/03/31 19:53:48 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int	main(void)
{
	
	{
		try
		{
			Bureaucrat	gerard("Gerard", 1);
			Intern		someRandomIntern;
			Form*		rrf;

			std::cout << gerard << std::endl;

			rrf = someRandomIntern.makeForm("Shrubbery", "Garden");
			
			rrf->beSigned(gerard);
			std::cout << *rrf << std::endl;
			gerard.executeForm(*rrf);

			delete rrf;
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
			Bureaucrat	gerard("Gerard", 145);
			Intern		someRandomIntern;
			Form*		rrf;

			std::cout << gerard << std::endl;

			rrf = someRandomIntern.makeForm("CERFA", "Gerard");
			
			rrf->beSigned(gerard);
			std::cout << rrf << std::endl;
			gerard.executeForm(*rrf);

			delete rrf;
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
			Intern		someRandomIntern;
			Form*		rrf;
			
			
			std::cout << robert << std::endl;
			
			rrf = someRandomIntern.makeForm("Robotomy", "Bender");

			rrf->beSigned(robert);
			std::cout << *rrf << std::endl;
			robert.executeForm(*rrf);
			
			delete rrf;
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
			Bureaucrat	ministre("Minister", 25);
			Bureaucrat	president(ministre);
			Intern		someRandomIntern;
			Form*		rrf;

			for (int i = 0; i < 20; i++)
				president.gradeIncrement();
			
			std::cout << ministre << std::endl;
			std::cout << president << std::endl;
			
			rrf = someRandomIntern.makeForm("Presidential Pardon", "Trump");
			rrf->beSigned(ministre);

			std::cout << *rrf << std::endl;
			
			ministre.executeForm(*rrf);
			
			delete rrf;
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
			Bureaucrat	ministre("Minister", 25);
			Bureaucrat	president(ministre);
			Intern		someRandomIntern;
			Form*		rrf;

			for (int i = 0; i < 20; i++)
				president.gradeIncrement();
			
			std::cout << ministre << std::endl;
			std::cout << president << std::endl;
			
			rrf = someRandomIntern.makeForm("Presidential Pardon", "Trump");
			rrf->beSigned(ministre);

			std::cout << *rrf << std::endl;

			president.executeForm(*rrf);

			delete rrf;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}