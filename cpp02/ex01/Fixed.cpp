/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:54:17 by mababou           #+#    #+#             */
/*   Updated: 2022/03/28 17:24:57 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static float	pow(int val, int power)
{
	float powered = val;
	
	while (--power > 0) {
		powered *= val;
	}
	return (powered);
}

Fixed::Fixed(void): _raw(0)
{
	std::cout << "\e[3m Default constructor called\e[0m" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "\e[3m Copy constructor called\e[0m" << std::endl;
	this->_raw = src.getRawBits();
}

Fixed::Fixed(const int n)
{
	std::cout << "\e[3m Int constructor called\e[0m" << std::endl;
	if (n > 8388607 || n < -8388608)
		std::cerr << "\e[31m Warning: the raw bits are overflowed\e[0m" << std::endl;
	this->_raw = n * pow(2, this->_frac_len);
}

Fixed::Fixed(const float f)
{
	std::cout << "\e[3m Float constructor called\e[0m" << std::endl;
	if (f > 8388607.99609 || f < -8388608)
		std::cerr << "\e[31m Warning: the raw bits are overflowed\e[0m" << std::endl;
	this->_raw = roundf(f * pow(2, this->_frac_len));
}

Fixed::~Fixed(void)
{
	std::cout << "\e[3m Destructor called\e[0m" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "\e[3m Copy assignment operator called\e[0m" << std::endl;
	this->_raw = rhs.getRawBits();

	return (*this);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

int	Fixed::getRawBits(void) const
{
	return (this->_raw);
}

void	Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
}

float	Fixed::toFloat(void) const
{
	float	f;

	f = (float)(this->_raw / pow(2, this->_frac_len));
	return (f);
}

int		Fixed::toInt(void) const
{
	float	i = 0;

	i = this->_raw / pow(2, this->_frac_len);
	return (i);
}