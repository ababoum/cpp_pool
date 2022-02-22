/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:04:42 by mababou           #+#    #+#             */
/*   Updated: 2022/02/22 18:18:59 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	punch(ClapTrap & hitter, ClapTrap & hittee)
{
	hitter.attack(hittee.getName());
	if (hitter.getEnergyPoints() != 0 && hitter.getHitPoints() != 0)
		hittee.takeDamage(hitter.getAttackDamage());
}

int main(void)
{
	ClapTrap	fighter1("Pikachu");
	ClapTrap	fighter2("Mew");

	fighter1.setAttackDamage(6);
	
	punch(fighter2, fighter1);
	
	fighter2.setAttackDamage(5);

	punch(fighter2, fighter1);
	punch(fighter1, fighter2);

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
	
	return (0);
}