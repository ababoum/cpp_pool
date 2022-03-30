/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:38:31 by mababou           #+#    #+#             */
/*   Updated: 2022/03/30 20:01:19 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource(): _cursor(0)
{
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	this->_cursor = src._cursor;
	
	int i;
	for (i = 0; i < 4; i++)
		this->_materia_list[i] = src._materia_list[i]->clone();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->_cursor; i++) {
		delete this->_materia_list[i];
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	if ( this != &rhs )
	{
		this->_cursor = rhs._cursor;
	
		int i;
		for (i = 0; i < 4; i++)
			this->_materia_list[i] = rhs._materia_list[i]->clone();
	}
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/

void		MateriaSource::learnMateria(AMateria* srcMateria)
{
	if (this->_cursor < 4)
	{
		this->_materia_list[this->_cursor] = srcMateria->clone();
		this->_cursor++;
	}
	delete srcMateria;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	int	i;
	
	for (i = 0; i < 4; i++) {
		if (this->_materia_list[i]->getType() == type)
			return (this->_materia_list[i]->clone());
	}

	return (0);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

AMateria	**MateriaSource::getMateriaList(void)
{
	return (this->_materia_list);
}

/* ************************************************************************** */