/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:57:35 by mababou           #+#    #+#             */
/*   Updated: 2022/02/16 18:54:07 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name,  Weapon weapon): _name(name), _weapon(weapon)
{
	return ;
}

HumanA::~HumanA(void)
{
	return ;
}

void	HumanA::setName(std::string name)
{
	this->_name = name;
}

std::string	HumanA::getName(void) const
{
	return this->_name;
}

void	HumanA::setWeapon(Weapon weapon)
{
	this->_weapon = weapon;
}

Weapon	HumanA::getWeapon(void) const
{
	return this->_weapon;
}

void	HumanA::attack(void)
{
	std::cout << this->getName() << " attacks with their " << *(this->getWeapon().getType()) << std::endl;
}
