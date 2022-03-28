/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:30:10 by mababou           #+#    #+#             */
/*   Updated: 2022/03/28 12:09:40 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath> // for roundf

class	Fixed {
	
public:

	Fixed(void);
	Fixed(Fixed const & src);
	Fixed(const int n);
	Fixed(const float f);
	~Fixed(void);

	Fixed &	operator=(Fixed const & rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:

	int					_raw;
	static const int	_frac_len = 8;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif