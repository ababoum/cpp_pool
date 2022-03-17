/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:55:33 by mababou           #+#    #+#             */
/*   Updated: 2022/03/17 20:15:49 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

int	main(void)
{

	Bureaucrat robert("Robert", 140);
	Bureaucrat albert("Albert", 150);
	Bureaucrat gerard("Gerard", 1);

	std::cout << robert << std::endl;
	std::cout << albert << std::endl;
	std::cout << gerard << std::endl;

	Form	cerfa1522("Cerfa 1522", 50, 50);
	Form	cerfa1534("Cerfa 1534", 500, 50);

	cerfa1522.beSigned(albert);
	cerfa1534.beSigned(albert);
	
	return (0);
}