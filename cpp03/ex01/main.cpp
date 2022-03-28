/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:04:42 by mababou           #+#    #+#             */
/*   Updated: 2022/03/28 19:58:52 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	punch(ScavTrap & hitter, ScavTrap & hittee)
{
	hitter.attack(hittee.getName());
	if (hitter.getEnergyPoints() != 0 && hitter.getHitPoints() != 0)
		hittee.takeDamage(hitter.getAttackDamage());
}

int main(void)
{
	ScavTrap	fighter1("Pikachu");
	ScavTrap	fighter2(fighter1);
	ScavTrap	fighter3;

	fighter3 = fighter1;
	fighter3.guardGate();
	fighter2.setName("Pikachu Clone");
	fighter2.guardGate();
	
	punch(fighter2, fighter1);
	punch(fighter2, fighter1);
	punch(fighter1, fighter2);

	fighter1.guardGate();

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