/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:01:22 by mababou           #+#    #+#             */
/*   Updated: 2022/03/25 13:56:29 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void)
{
	return ;
}

HumanB::HumanB(std::string name): _name(name)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::setName(std::string name)
{
	this->_name = name;
}

std::string	HumanB::getName(void) const
{
	return this->_name;
}

void	HumanB::setWeapon(Weapon & weapon)
{
	this->_weapon = &weapon;
}

Weapon	*HumanB::getWeapon(void) const
{
	return this->_weapon;
}

void	HumanB::attack(void)
{
	std::cout << this->getName() << " attacks with their " << this->_weapon->getType() << std::endl;
}
