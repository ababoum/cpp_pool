/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:33:02 by mababou           #+#    #+#             */
/*   Updated: 2022/02/23 16:30:03 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	std::cout << "\e[1;30;48m Dog \e[0m ";
	std::cout << " \e[3mDefault constructor called\e[0m" << std::endl;
	this->type_ = "Dog";
}

Dog::Dog( const Dog &)
{
	std::cout << "\e[1;30;48m Dog\e[0m ";
	std::cout << " \e[3mCopy constructor called\e[0m" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "\e[1;30;48m Dog\e[0m ";
	std::cout << " \e[3mDestructor called\e[0m" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const &)
{
	std::cout << "\e[1;30;48m Dog\e[0m ";
	std::cout << " \e[3mAssignement operator called\e[0m" << std::endl;
	
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Dog const & i )
{
	o << i.getType();
	
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Dog::makeSound(void) const
{
	std::cout << "\"Wwwwwwwwwwaaf! 🐶\"" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */