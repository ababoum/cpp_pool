/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:34:22 by mababou           #+#    #+#             */
/*   Updated: 2022/03/28 16:41:00 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed det1;
	Fixed det2;

	const Point v0(a);
	const Point v1(b.getX() - a.getX(), b.getY() - a.getY());
	const Point v2(c.getX() - a.getX(), c.getY() - a.getY());

	if (Point::scalar(v1, v2) == 0)
	{
		if (point.getX() >= a.getX() && point.getX() <= b.getX() && 
		point.getY() >= a.getY() && point.getY() <= b.getY())
			return (true);
		else
			return (false);
	}
	
	det1 = (Point::scalar(point, v2) - Point::scalar(v0, v2)) / Point::scalar(v1, v2);
	det2 = (Point::scalar(point, v1) - Point::scalar(v0, v1)) / Point::scalar(v1, v2);

	if (det1 > 0 && det2 < 0 && det1 - det2 < 1)
		return (true);
	else
		return (false);
}