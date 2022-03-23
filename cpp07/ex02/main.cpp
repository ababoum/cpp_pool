/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:58:57 by mababou           #+#    #+#             */
/*   Updated: 2022/03/23 16:06:00 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	try {
	
	Array<int> lst(5);
	
	lst[3] = 42;
	for (int i = 0; i < 5; i++)
		std::cout << lst[i] << std::endl;
	}
	catch (Array<int>::OutOfRangeException e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}