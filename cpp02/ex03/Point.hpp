/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:05:15 by mababou           #+#    #+#             */
/*   Updated: 2022/03/28 16:42:48 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
# include "Fixed.hpp"

class Point
{

	public:

		Point();
		Point( Point const & src );
		Point(const float x0, const float y0);
		Point(const Fixed x0, const Fixed y0);
		~Point();

		Point &		operator=( Point const & rhs );

		const Fixed 	&getX(void) const;
		const Fixed		&getY(void) const;

		static Fixed 	scalar(Point const &P1, Point const &P2);

	private:
		Fixed const _x;
		Fixed const _y;

};

std::ostream &			operator<<( std::ostream & o, Point const & i );

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif /* *********************************************************** POINT_H */