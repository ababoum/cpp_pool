/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:33:02 by mababou           #+#    #+#             */
/*   Updated: 2022/03/30 13:48:32 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	std::cout << "\e[1;30;48m Dog\e[0m ";
	std::cout << "\e[3mDefault constructor called\e[0m" << std::endl;
	this->type_ = "Dog";
	this->_brain = new Brain();
}

Dog::Dog( const Dog & src)
{
	std::cout << "\e[1;30;48m Dog\e[0m ";
	std::cout << "\e[3mCopy constructor called\e[0m" << std::endl;
	this->type_ = src.type_;
	this->_brain = new Brain();
	*(this->_brain) = *(src._brain);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "\e[1;30;48m Dog\e[0m ";
	std::cout << "\e[3mDestructor called\e[0m" << std::endl;
	delete this->_brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs)
{
	std::cout << "\e[1;30;48m Dog\e[0m ";
	std::cout << "\e[3mAssignment operator called\e[0m" << std::endl;
	
	if ( this != &rhs )
	{
		this->type_ = rhs.getType();
		*(this->_brain) = *(rhs._brain);
	}

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

Brain		*Dog::getBrain(void)
{
	return (this->_brain);
}

/* ************************************************************************** */