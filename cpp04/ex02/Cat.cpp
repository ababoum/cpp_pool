/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:33:09 by mababou           #+#    #+#             */
/*   Updated: 2022/03/30 13:55:54 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(void)
{
	std::cout << "\e[1;30;47m Cat\e[0m ";
	std::cout << "\e[3mDefault constructor called\e[0m" << std::endl;
	this->type_ = "Cat";
	this->_brain = new Brain();
}

Cat::Cat( const Cat & src)
{
	std::cout << "\e[1;30;47m Cat\e[0m ";
	std::cout << "\e[3mCopy constructor called\e[0m" << std::endl;
	this->type_ = src.type_;
	this->_brain = new Brain();
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

Cat &				Cat::operator=( Cat const & rhs)
{
	std::cout << "\e[1;30;47m Cat\e[0m ";
	std::cout << "\e[3mAssignment operator called\e[0m" << std::endl;
	
	if ( this != &rhs )
	{
		this->type_ = rhs.getType();
		*(this->_brain) = *(rhs._brain);
	}
	
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

Brain		*Cat::getBrain(void)
{
	return (this->_brain);
}


/* ************************************************************************** */