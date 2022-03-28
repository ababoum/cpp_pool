/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:31:33 by mababou           #+#    #+#             */
/*   Updated: 2022/03/28 20:01:51 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal()
{
	std::cout << "\e[1;30;43m WrongAnimal \e[0m ";
	std::cout << " \e[3mDefault constructor called\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src )
{
	std::cout << "\e[1;30;43m WrongAnimal\e[0m ";
	std::cout << " \e[3mCopy constructor called\e[0m" << std::endl;
	
	this->type_ = src.getType();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[1;30;43m WrongAnimal\e[0m ";
	std::cout << " \e[3mDestructor called\e[0m" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &				WrongAnimal::operator=( WrongAnimal const & rhs )
{
	std::cout << "\e[1;30;43m WrongAnimal\e[0m ";
	std::cout << " \e[3mAssignment operator called\e[0m" << std::endl;
	
	if ( this != &rhs )
	{
		this->type_ = rhs.getType();
	}
	
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i )
{
	o << i.getType();
	
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string		WrongAnimal::getType(void) const
{
	return (this->type_);
}

void			WrongAnimal::setType(std::string type)
{
	this->type_ = type;
}

void			WrongAnimal::makeSound(void) const
{
	std::cout << "\"NOISE\"" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */