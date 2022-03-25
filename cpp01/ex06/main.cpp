/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:04:42 by mababou           #+#    #+#             */
/*   Updated: 2022/03/25 18:05:10 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Invalid number of arguments. Please launch the program with the acceptable complaining level." << std::endl;
		return (0);
	}
	std::string filter(av[1]);
	Harl	chipie(filter);

	if (chipie.getFilter() == 42)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}
	
	chipie.complain("DEBUG");
	chipie.complain("INFO");
	chipie.complain("WARNING");
	chipie.complain("ERROR");	
	
	return (0);
}