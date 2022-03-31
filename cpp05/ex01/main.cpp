/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:55:33 by mababou           #+#    #+#             */
/*   Updated: 2022/03/31 10:57:17 by mababou          ###   ########.fr       */
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
	// Form	cerfa1000("Cerfa 1000", 1, 151);
	Form	cerfa1001("Cerfa 1001", 1, 1);

	cerfa1522.beSigned(albert);
	cerfa1534.beSigned(albert);
	cerfa1001.beSigned(albert);

	std::cout << cerfa1522 << std::endl;
	std::cout << cerfa1534 << std::endl;
	
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}