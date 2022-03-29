/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:33:09 by mababou           #+#    #+#             */
/*   Updated: 2022/03/29 19:24:25 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat()
{
	std::cout << "\e[1;30;47m WrongCat\e[0m ";
	std::cout << "\e[3mDefault constructor called\e[0m" << std::endl;
	this->type_ = "WrongCat";
}

WrongCat::WrongCat( const WrongCat &)
{
	std::cout << "\e[1;30;47m WrongCat\e[0m ";
	std::cout << "\e[3mCopy constructor called\e[0m" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << "\e[1;30;47m WrongCat\e[0m ";
	std::cout << "\e[3mDestructor called\e[0m" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &				WrongCat::operator=( WrongCat const & rhs)
{
	std::cout << "\e[1;30;47m WrongCat\e[0m ";
	std::cout << "\e[3mAssignment operator called\e[0m" << std::endl;
	
	if ( this != &rhs )
	{
		this->type_ = rhs.getType();
	}
	
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongCat const & i )
{
	o << i.getType();
	
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	WrongCat::makeSound(void) const
{
	std::cout << "\"Meoow 🐱\"" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */