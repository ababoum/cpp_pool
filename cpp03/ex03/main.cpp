/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:04:42 by mababou           #+#    #+#             */
/*   Updated: 2022/02/23 14:26:23 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	punch(FragTrap & hitter, FragTrap & hittee)
{
	hitter.attack(hittee.getName());
	if (hitter.getEnergyPoints() != 0 && hitter.getHitPoints() != 0)
		hittee.takeDamage(hitter.getAttackDamage());
}

int main(void)
{
	FragTrap	fighter1("Pikachu");
	FragTrap	fighter2("Mew");


	punch(fighter2, fighter1);
	punch(fighter2, fighter1);
	punch(fighter1, fighter2);

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