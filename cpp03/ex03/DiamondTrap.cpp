/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:31:38 by mababou           #+#    #+#             */
/*   Updated: 2022/03/28 21:07:04 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap()
{
	std::cout << "\e[1;46mDiamondTrap\e[0m ";
	std::cout << "\e[3mDefault constructor called\e[0m" << std::endl;
	this->_hit_points = FragTrap::init_hit_points;
	this->_energy_points = ScavTrap::init_energy_points;
	this->_attack_damage = FragTrap::init_attack_damage;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name)
{
	std::cout << "\e[1;46mDiamondTrap\e[0m ";
	std::cout << "\e[3mName constructor called\e[0m" << std::endl;
	this->_hit_points = FragTrap::init_hit_points;
	this->_energy_points = ScavTrap::init_energy_points;
	this->_attack_damage = FragTrap::init_attack_damage;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src )
{
	std::cout << "\e[1;46mDiamondTrap\e[0m ";
	std::cout << "\e[3mCopy constructor called\e[0m" << std::endl;
	*this = src ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "\e[1;46mDiamondTrap\e[0m ";
	std::cout << "\e[3mDestructor called\e[0m" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
{
	if ( this != &rhs )
	{
		*this = rhs;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i )
{
	o << i.getName();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "\e[1;46mDiamondTrap\e[0m ";
	std::cout << "Who am I? Name: " << *this;
	std::cout << " and ClapTrap Name: " << ClapTrap::getName();
	std::cout << "_clap_name" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */