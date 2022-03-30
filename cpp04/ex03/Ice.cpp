/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:10:45 by mababou           #+#    #+#             */
/*   Updated: 2022/03/30 20:13:28 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice(): AMateria("ice")
{
}

Ice::Ice( const Ice & src ): AMateria("ice")
{
	this->type_ = src.getType();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &				Ice::operator=( Ice const & rhs )
{
	if ( this != &rhs )
	{
		this->type_ = rhs.getType();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

Ice* 		Ice::clone() const
{
	Ice	*clone = new Ice();
	
	return (clone);
}

void 		Ice::use(ICharacter& target)
{
	std::cout << "\"*shoots an ice bolt at " << target.getName() << "*\"";
	std::cout << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */