/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:33:02 by mababou           #+#    #+#             */
/*   Updated: 2022/03/28 20:01:51 by mababou          ###   ########.fr       */
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
	this->_brain = new Brain();
}

Dog::Dog( const Dog & src )
{
	std::cout << "\e[1;30;48m Dog\e[0m ";
	std::cout << " \e[3mCopy constructor called\e[0m" << std::endl;
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain = src._brain;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "\e[1;30;48m Dog\e[0m ";
	std::cout << " \e[3mDestructor called\e[0m" << std::endl;
	delete this->_brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const &)
{
	std::cout << "\e[1;30;48m Dog\e[0m ";
	std::cout << " \e[3mAssignment operator called\e[0m" << std::endl;
	
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