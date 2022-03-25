/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:04:42 by mababou           #+#    #+#             */
/*   Updated: 2022/03/25 17:15:40 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	chipie;

	std::cout << std::endl;
	chipie.complain("DEBUG");
	std::cout << std::endl;
	chipie.complain("INFO");
	std::cout << std::endl;
	chipie.complain("WARNING");
	std::cout << std::endl;
	chipie.complain("ERROR");
	std::cout << std::endl;
	
	return (0);
}