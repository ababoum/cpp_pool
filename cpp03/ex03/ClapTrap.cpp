/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:29:17 by mababou           #+#    #+#             */
/*   Updated: 2022/03/28 20:41:14 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(): _name(""), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "\e[1mClapTrap \e[0m";
	std::cout << "\e[3mDefault constructor called\e[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "\e[1mClapTrap \e[0m";
	std::cout << "\e[3mName constructor called\e[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & src)
{
	std::cout << "\e[1mClapTrap \e[0m";
	std::cout << "\e[3mCopy constructor called\e[0m" << std::endl;
	this->_name = src.getName();
	this->_hit_points = src.getHitPoints();
	this->_energy_points = src.getEnergyPoints();
	this->_attack_damage = src.getAttackDamage();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "\e[1mClapTrap \e[0m";
	std::cout << "\e[3mDestructor called\e[0m" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &		ClapTrap::operator=(ClapTrap const & rhs)
{
	if ( this != &rhs )
	{
		this->_name = rhs.getName();
		this->_hit_points = rhs.getHitPoints();
		this->_energy_points = rhs.getEnergyPoints();
		this->_attack_damage = rhs.getAttackDamage();
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & o, ClapTrap const & i)
{
	o << i.getName();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string		ClapTrap::getName(void) const
{
	return this->_name;
}

void			ClapTrap::setName(std::string name)
{
	this->_name = name;
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return this->_hit_points;
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return this->_energy_points;
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return this->_attack_damage;
}

void			ClapTrap::setAttackDamage(unsigned int attack)
{
	std::cout << "\e[1mClapTrap \e[0m";
	std::cout << *this << "'s attack is set to " << attack << std::endl; 
	this->_attack_damage = attack;
}

void			ClapTrap::attack(const std::string& target)
{
	std::cout << "\e[1mClapTrap \e[0m";
	if (this->_hit_points == 0)
		std::cout << *this << " has no hit point and cannot attack" << std::endl;
	else if (this->_energy_points == 0)
		std::cout << *this << " has no energy and cannot attack" << std::endl;
	else if (this->_attack_damage == 0)
		std::cout << *this << " tries to attack, but it has no attack and cannot inflict damage!" << std::endl;
	else
	{
		std::cout << *this << " attacks " << target << ", causing \e[91m";
		std::cout << this->getAttackDamage() << " point";
		if (this->getAttackDamage() > 1)
			std::cout << "s";
		std::cout << " of damage!\e[0m" << std::endl;
		this->_energy_points--;
	}
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "\e[1mClapTrap \e[0m";
	if (this->_hit_points == 0)
		std::cout << *this << " has zero hit points and cannot lose any more" << std::endl;
	else
	{
		if (amount > this->_hit_points)
		{
			amount = this->_hit_points;
			this->_hit_points = 0;
		}
		else
			this->_hit_points -= amount;
		std::cout << *this << " loses " << amount << " hit point";
		if (amount > 1)
			std::cout << "s";
		std::cout << " and has ";
		std::cout << this->getHitPoints() << " left" << std::endl;
	}
	
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "\e[1mClapTrap \e[0m";
	if (this->_energy_points == 0)
		std::cout << *this << " has no energy points and cannot repair itself" << std::endl;
	else if (this->_hit_points == 0)
		std::cout << *this << " has no hit points and cannot repair itself" << std::endl;
	else
	{
		std::cout << *this << " repairs itself and gains \e[92m" << amount << " hit point";
		if (amount > 1)
			std::cout << "s";
		std::cout << "\e[0m" << std::endl;
		this->_energy_points--;
		this->_hit_points += amount;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */