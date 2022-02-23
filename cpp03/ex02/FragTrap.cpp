/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:41:37 by mababou           #+#    #+#             */
/*   Updated: 2022/02/23 15:08:26 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap()
{
	std::cout << "\e[1;45mFragTrap \e[0m";
	std::cout << "\e[3mDefault constructor summoned\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "\e[1;45mFragTrap \e[0m";
	std::cout << "\e[3mName constructor summoned\e[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap & src)
{
	std::cout << "\e[1;45mFragTrap \e[0m";
	std::cout << "\e[3mCopy constructor summoned\e[0m" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << "\e[1;45mFragTrap \e[0m";
	std::cout << "\e[3mDestructor summoned\e[0m" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const &)
{
	return *this;
}

std::ostream &			operator<<( std::ostream & o, FragTrap const & i )
{
	o << i.getName();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void					FragTrap::highFivesGuys(void) const
{
	std::cout << "\e[1;45mFragTrap \e[0m";
	std::cout << *this << " high fives 🙌 " << std::endl;
}

void					FragTrap::attack(const std::string& target)
{
	std::cout << "\e[1;45mFragTrap \e[0m";
	if (this->_hit_points == 0)
		std::cout << *this << " cannot attack with 0 hit point" << std::endl;
	else if (this->_energy_points == 0)
		std::cout << *this << " cannot attack with 0 energy point" << std::endl;
	else if (this->_attack_damage == 0)
		std::cout << *this << " cannot inflict damage with 0 attack" << std::endl;
	else
	{
		std::cout << *this << " attacks " << target << ", dealing a swooping \e[91m";
		std::cout << this->getAttackDamage() << " point";
		if (this->getAttackDamage() > 1)
			std::cout << "s";
		std::cout << " of wild damage!\e[0m" << std::endl;
		this->_energy_points--;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */