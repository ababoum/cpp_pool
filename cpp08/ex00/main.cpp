/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:58:57 by mababou           #+#    #+#             */
/*   Updated: 2022/03/23 18:57:39 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::list<int> lst;

	lst.push_back(100);
	lst.push_back(50);
	lst.push_back(20);
	lst.push_back(10);
	lst.push_back(0);
	lst.push_back(-50);

	std::cout << easyfind(lst, 50) << std::endl;
	
	return (0);
}