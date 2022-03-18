/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:55:33 by mababou           #+#    #+#             */
/*   Updated: 2022/03/18 13:58:18 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

int	main(void)
{
	try
	{
	Bureaucrat robert("Robert", 140);
	Bureaucrat albert("Albert", 10);
	Bureaucrat gerard("Gerard", 1);

	std::cout << robert << std::endl;
	std::cout << albert << std::endl;
	std::cout << gerard << std::endl;

	Form	cerfa1522("Cerfa 1522", 50, 50);
	Form	cerfa1534("Cerfa 1534", 25, 50);

	cerfa1522.beSigned(albert);
	cerfa1534.beSigned(albert);

	std::cout << cerfa1522 << std::endl;
	std::cout << cerfa1534 << std::endl;
	
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
	}	
	
	return (0);
}