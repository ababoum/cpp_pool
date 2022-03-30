/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:33:38 by mababou           #+#    #+#             */
/*   Updated: 2022/03/30 15:35:40 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

IMateriaSource::IMateriaSource()
{
}

IMateriaSource::IMateriaSource( const IMateriaSource & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

IMateriaSource::~IMateriaSource()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

IMateriaSource &				IMateriaSource::operator=( IMateriaSource const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */