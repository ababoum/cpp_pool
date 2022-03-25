/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:54:17 by mababou           #+#    #+#             */
/*   Updated: 2022/03/25 18:54:40 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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
	this->_raw = n;
}

Fixed::Fixed(const float f)
{
	std::cout << "\e[3m Float constructor called\e[0m" << std::endl;
	this->_raw = f;
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

float	Fixed::getRawBits(void) const
{
	return (this->_raw);
}

void	Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
}

float	Fixed::toFloat(void) const
{
	return (this->_raw);
}

int	Fixed::toInt(void) const
{
	return (roundf(this->_raw));
}