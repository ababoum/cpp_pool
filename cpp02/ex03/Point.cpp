/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:05:15 by mababou           #+#    #+#             */
/*   Updated: 2022/03/28 17:18:13 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point(void)
{
	return ;
}

Point::Point( const Point & src ): _x(src.getX()), _y(src.getY())
{
	return ;
}

Point::Point(const float x0, const float y0): _x(Fixed(x0)), _y(Fixed(y0))
{
	return ;
}

Point::Point(const Fixed x0, const Fixed y0): _x(x0), _y(y0)
{
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point &				Point::operator=( Point const & rhs )
{
	if (this != &rhs )
	{
		// this->setX(rhs.getX());
		// this->setY(rhs.getY());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Point const & i )
{
	o << "x = " << i.getX() << " and y =" << i.getY();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Fixed	Point::scalar(Point const &P1, Point const &P2)
{
	return ((P1.getX() * P2.getY()) - (P1.getY() * P2.getX()));
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const Fixed 	&Point::getX(void) const
{
	return (this->_x);
}

const Fixed 	&Point::getY(void) const
{
	return (this->_y);
}

/* ************************************************************************** */