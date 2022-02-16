/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:06:59 by mababou           #+#    #+#             */
/*   Updated: 2022/02/16 17:20:05 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *lst = zombieHorde(5, "Einstein");

	int i = 0;
	while (i < 5)
		lst[i++].announce();

	i = 0;
	
	delete [] lst;
	
	return (0);	
}