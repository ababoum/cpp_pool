/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:12:06 by mababou           #+#    #+#             */
/*   Updated: 2022/04/01 21:10:24 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Converter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Incorrect number of arguments" << std::endl;
		std::cout << "\e[91mExpected format : \e[3m./convert <litteral char, int, float, or double>\e[0m" << std::endl;
		return (1);
	}
	
	Converter	capsule(av[1]);
	
	std::cout << "char:   " << capsule.toChar() << std::endl;
	std::cout << "int:    " << capsule.toInt() << std::endl;
	std::cout << "float:  " << capsule.toFloat() << std::endl;
	std::cout << "double: " << capsule.toDouble() << std::endl;
	
	return (0);
}