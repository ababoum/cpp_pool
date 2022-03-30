/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:38:40 by mababou           #+#    #+#             */
/*   Updated: 2022/03/30 20:26:07 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(): _cursor(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name):  _cursor(0), _name(name)
{
}

Character::Character( const Character & src ): _cursor(src._cursor), _name(src._name)
{
	int i;
	
	for (i = 0; i < src._cursor; i++)
		this->_inventory[i] = src._inventory[i]->clone();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (int i = 0; i < this->_cursor; i++) {
		delete this->_inventory[i];
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		this->_cursor = rhs._cursor;
		this->_name = rhs._name;
		
		int i;
		for (i = 0; i < 4; i++)
			this->_inventory[i] = rhs._inventory[i]->clone();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Character const & i )
{
	o << i.getName();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void 		Character::equip(AMateria* m)
{	
	if (this->_cursor < 4)
	{
		this->_inventory[this->_cursor] = m;
		this->_cursor++;
	}
	else
	{
		std::cout << "Cannot equip the Materia (no space left)" << std::endl;
	}
}

void 		Character::unequip(int idx)
{
	int	i;
	
	if (idx >= 0 && idx < this->_cursor)
	{
		for (i = idx ; i < this->_cursor - 1; i++)
			this->_inventory[i] = this->_inventory[i + 1];
		this->_inventory[this->_cursor - 1] = NULL;
		this->_cursor--;
	}
}

void		Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < this->_cursor)
	{
		this->_inventory[idx]->use(target);
	}
	else
	{
		std::cout << "No Materia at given index in the inventory" << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & Character::getName() const
{
	return (this->_name);
}

// AMateria			**Character::getInventory(void)
// {
// 	return (this->_inventory);
// }

/* ************************************************************************** */