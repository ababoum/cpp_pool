/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:04:42 by mababou           #+#    #+#             */
/*   Updated: 2022/03/28 17:27:07 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) {
	
	// Point P1(1, 0);
	// Point P2(0, 1);
	// Point P3(0, 0);
	// Point test(-0.4f, -0.4f);

	// if (bsp(P1, P2, P3, test))
	// 	std::cout << "\e[32mThe point is inside the triangle\e[0m" << std::endl;
	// else
	// 	std::cout << "\e[31mThe point is outside the triangle\e[0m" << std::endl;


	Point P1(5, 0);
	Point P2(0, 5);
	Point P3(-5, 0);
	Point test(0, 4);

	if (bsp(P1, P2, P3, test))
		std::cout << "\e[32mThe point is inside the triangle\e[0m" << std::endl;
	else
		std::cout << "\e[31mThe point is outside the triangle\e[0m" << std::endl;

	
	return 0;
}