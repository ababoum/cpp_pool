/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:54:17 by mababou           #+#    #+#             */
/*   Updated: 2022/03/25 18:53:12 by mababou          ###   ########.fr       */
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

int	Fixed::getRawBits(void) const
{
	std::cout << "\e[3m getRawBits member function called\e[0m" << std::endl;
	return (this->_raw);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "\e[3m setRawBits member function called\e[0m" << std::endl;
	this->_raw = raw;
}
