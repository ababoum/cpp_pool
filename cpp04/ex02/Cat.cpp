/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:33:09 by mababou           #+#    #+#             */
/*   Updated: 2022/03/29 16:06:49 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	std::cout << "\e[1;30;47m Cat\e[0m ";
	std::cout << "\e[3mDefault constructor called\e[0m" << std::endl;
	this->type_ = "Cat";
	this->_brain = new Brain();
}

Cat::Cat( const Cat & src )
{
	std::cout << "\e[1;30;47m Cat\e[0m ";
	std::cout << "\e[3mCopy constructor called\e[0m" << std::endl;
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		*(this->_brain) = *(src._brain);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "\e[1;30;47m Cat\e[0m ";
	std::cout << "\e[3mDestructor called\e[0m" << std::endl;
	delete this->_brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const &)
{
	std::cout << "\e[1;30;47m Cat\e[0m ";
	std::cout << "\e[3mAssignment operator called\e[0m" << std::endl;
	
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cat const & i )
{
	o << i.getType();
	
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Cat::makeSound(void) const
{
	std::cout << "\"Meoow 🐱\"" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */