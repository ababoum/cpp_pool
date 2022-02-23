/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:31:33 by mababou           #+#    #+#             */
/*   Updated: 2022/02/23 16:12:21 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	std::cout << "\e[1;30;43m Animal \e[0m ";
	std::cout << " \e[3mDefault constructor called\e[0m" << std::endl;
}

Animal::Animal( const Animal & src )
{
	std::cout << "\e[1;30;43m Animal\e[0m ";
	std::cout << " \e[3mCopy constructor called\e[0m" << std::endl;
	
	this->type_ = src.getType();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "\e[1;30;43m Animal\e[0m ";
	std::cout << " \e[3mDestructor called\e[0m" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
{
	std::cout << "\e[1;30;43m Animal\e[0m ";
	std::cout << " \e[3mAssignement operator called\e[0m" << std::endl;
	
	if ( this != &rhs )
	{
		this->type_ = rhs.getType();
	}
	
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Animal const & i )
{
	o << i.getType();
	
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string		Animal::getType(void) const
{
	return (this->type_);
}

void			Animal::setType(std::string type)
{
	this->type_ = type;
}

void			Animal::makeSound(void) const
{
	std::cout << "\"NOISE\"" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */