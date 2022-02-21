/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:04:42 by mababou           #+#    #+#             */
/*   Updated: 2022/02/21 15:59:25 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Invalid number of arguments. Please launch the program with the acceptable complaining level." << std::endl;
		return (0);
	}

	Karen	chipie;
	int		filter;

	filter = chipie.convert_filter(av[1]);

	if (filter == 42)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}

	chipie.complain("DEBUG", filter);
	chipie.complain("INFO", filter);
	chipie.complain("WARNING", filter);
	chipie.complain("ERROR", filter);	
	
	return (0);
}