/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:06:59 by mababou           #+#    #+#             */
/*   Updated: 2022/02/16 16:22:41 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void 	randomChump(std::string name);
Zombie* newZombie(std::string name);

int main(void)
{
	Zombie *Zomb1 = newZombie("Zomb1");
	Zombie *Zomb2 = newZombie("Zomb2");

	randomChump("Rand1");
	randomChump("Rand2");

	Zomb1->announce();
	Zomb1->announce();
	Zomb1->announce();
	Zomb1->announce();
	Zomb2->announce();
	Zomb2->announce();
	Zomb2->announce();

	delete Zomb1;
	delete Zomb2;

	return (0);	
}