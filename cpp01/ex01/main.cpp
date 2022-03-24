/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:06:59 by mababou           #+#    #+#             */
/*   Updated: 2022/03/24 21:25:23 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *lst = zombieHorde(5, "Einstein");

	int i;
	for (i = 0; i < 5; i++)
		lst[i].announce();

	delete [] lst;
	return (0);	
}