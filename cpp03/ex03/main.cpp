/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:04:42 by mababou           #+#    #+#             */
/*   Updated: 2022/03/28 21:05:01 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	punch(DiamondTrap & hitter, DiamondTrap & hittee)
{
	hitter.attack(hittee.getName());
	if (hitter.getEnergyPoints() != 0 && hitter.getHitPoints() != 0)
		hittee.takeDamage(hitter.getAttackDamage());
}

int main(void)
{
	DiamondTrap	fighter1("Pikachu");
	DiamondTrap	fighter2("Mew");


	punch(fighter2, fighter1);
	punch(fighter2, fighter1);
	punch(fighter1, fighter2);

	fighter1.whoAmI();
	fighter1.guardGate();
	fighter1.highFivesGuys();

	fighter2.beRepaired(1);
	fighter2.beRepaired(1);
	fighter2.beRepaired(1);
	fighter1.beRepaired(1);
	fighter1.beRepaired(1);
	fighter1.beRepaired(1);
	fighter1.beRepaired(1);
	fighter1.beRepaired(1);
	fighter1.beRepaired(1);
	fighter1.beRepaired(1);
	fighter1.beRepaired(1);
	fighter1.beRepaired(1);
	
	punch(fighter2, fighter1);
	punch(fighter1, fighter2);

	punch(fighter2, fighter1);
	punch(fighter1, fighter2);

	punch(fighter2, fighter1);
	punch(fighter1, fighter2);

	punch(fighter2, fighter1);
	punch(fighter1, fighter2);
	
	return (0);
}