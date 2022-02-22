/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:30:10 by mababou           #+#    #+#             */
/*   Updated: 2022/02/22 09:55:44 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath> // for roundf

class	Fixed {
	
public:

	Fixed(void);
	Fixed(Fixed const & src);
	Fixed(const int);
	Fixed(const float);
	~Fixed(void);

	Fixed &	operator=(Fixed const & rhs);

	float	getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:

	float				_raw;
	static const int	_frac_len;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif