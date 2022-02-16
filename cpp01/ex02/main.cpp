/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:06:59 by mababou           #+#    #+#             */
/*   Updated: 2022/02/16 17:28:36 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{

	std::string item = "HI THIS IS BRAIN";
	std::string	*stringPTR = &item;
	std::string	&stringREF = item;

	std::cout << "----------------------" << std::endl;

	std::cout << &item << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	
	std::cout << "----------------------" << std::endl;

	std::cout << item << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	
	std::cout << "----------------------" << std::endl;
	
	return (0);	
}