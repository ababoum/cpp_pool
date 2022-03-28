/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:30:10 by mababou           #+#    #+#             */
/*   Updated: 2022/03/28 14:58:59 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath> // for roundf

# define	INT_MAX	2147483647
# define	INT_MIN	-2147483648
# define	EPSILON	0.00390625

class	Fixed {
	
public:

	Fixed(void);
	Fixed(Fixed const & src);
	Fixed(const int n);
	Fixed(const float f);
	~Fixed(void);

	Fixed &	operator =(Fixed const & rhs);
	
	

	Fixed & operator++(void);       // Prefix increment operator.
	Fixed operator++(int);     		// Postfix increment operator.
	Fixed & operator--(void);       // Prefix increment operator.
	Fixed operator--(int);     		// Postfix increment operator.

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	static	Fixed	&min(Fixed & fixed1, Fixed & fixed2);
	static	Fixed	min(Fixed const & fixed1, Fixed const & fixed2);
	static	Fixed	&max(Fixed & fixed1, Fixed & fixed2);
	static	Fixed	max(Fixed const & fixed1, Fixed const & fixed2);

private:

	int					_raw;
	static const int	_frac_len = 8;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

bool 	operator >(Fixed const & fixed1, Fixed const & fixed2);
bool 	operator <(Fixed const & fixed1, Fixed const & fixed2);
bool 	operator >=(Fixed const & fixed1, Fixed const & fixed2);
bool 	operator <=(Fixed const & fixed1, Fixed const & fixed2);
bool 	operator ==(Fixed const & fixed1, Fixed const & fixed2);
bool 	operator !=(Fixed const & fixed1, Fixed const & fixed2);

Fixed	operator +(Fixed const & fixed1, Fixed const & fixed2);
Fixed 	operator -(Fixed const & fixed1, Fixed const & fixed2);
Fixed 	operator *(Fixed const & fixed1, Fixed const & fixed2);
Fixed 	operator /(Fixed const & fixed1, Fixed const & fixed2);

#endif