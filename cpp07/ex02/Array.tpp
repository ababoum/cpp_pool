/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:23:14 by mababou           #+#    #+#             */
/*   Updated: 2022/03/23 11:39:29 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

void	Array::Array (void) {
	this->_array = 0;
	this->_size = 0;
}

template <typename T>
void	Array::Array (unsigned int n) {
	unsigned int	i;
	
	this->_array = new T(n);
	for (i = 0; i < n; i++) {
		this->_array[i] = 0;
	}
	this->_size = n;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Array::~Array()
{
	if (this->_size > 0)
		delete [] this->_array;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Array &		Array::operator[]( unsigned int index ) {
	if (index >= 0 && index < size)
		return (this->_array[index]);
	else
		throw Array::OutOfRangeException;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/