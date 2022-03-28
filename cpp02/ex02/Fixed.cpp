/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:54:17 by mababou           #+#    #+#             */
/*   Updated: 2022/03/28 17:25:03 by mababou          ###   ########.fr       */
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

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

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

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed(void)
{
	std::cout << "\e[3m Destructor called\e[0m" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

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

bool		operator >(Fixed const & fixed1, Fixed const & fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (true);
	else
		return (false);
}

bool		operator <(Fixed const & fixed1, Fixed const & fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (true);
	else
		return (false);
}

bool		operator >=(Fixed const & fixed1, Fixed const & fixed2)
{
	if (fixed1.getRawBits() >= fixed2.getRawBits())
		return (true);
	else
		return (false);
}

bool		operator <=(Fixed const & fixed1, Fixed const & fixed2)
{
	if (fixed1.getRawBits() <= fixed2.getRawBits())
		return (true);
	else
		return (false);
}

bool		operator ==(Fixed const & fixed1, Fixed const & fixed2)
{
	if (fixed1.getRawBits() == fixed2.getRawBits())
		return (true);
	else
		return (false);
}

bool		operator !=(Fixed const & fixed1, Fixed const & fixed2)
{
	if (fixed1.getRawBits() != fixed2.getRawBits())
		return (true);
	else
		return (false);
}

Fixed	operator+(Fixed const & fixed1, Fixed const & fixed2)
{
	Fixed	op_result;
	
	op_result.setRawBits(fixed1.getRawBits() + fixed2.getRawBits());

	return (op_result);
}

Fixed	operator*(Fixed const & fixed1, Fixed const & fixed2)
{
	Fixed	op_result;
	double	control;

	control = fixed1.getRawBits() * fixed2.getRawBits();
	if (control > INT_MAX || control < INT_MIN)
		std::cerr << "\e[31m Warning: multiplication result is int-overflowed\e[0m" << std::endl;
	op_result.setRawBits(fixed1.getRawBits() * fixed2.getRawBits() / pow(2, 8));

	return (op_result);
}

Fixed	operator-(Fixed const & fixed1, Fixed const & fixed2)
{
	Fixed	op_result;
	
	op_result.setRawBits(fixed1.getRawBits() - fixed2.getRawBits());

	return (op_result);
}

Fixed	operator/(Fixed const & fixed1, Fixed const & fixed2)
{
	Fixed	op_result;
	
	if (fixed2.getRawBits() == 0)
		std::cerr << "\e[31m Warning: division by zero is not authorized\e[0m" << std::endl;
	else
		op_result.setRawBits(pow(2, 8) * fixed1.getRawBits() / fixed2.getRawBits());

	return (op_result);
}


Fixed & Fixed::operator++(void)
{
	long	control;

	control = this->toInt() + EPSILON;
	if (control > 8388607)
		std::cerr << "\e[31m Warning: the raw bits are overflowed\e[0m" << std::endl;
	this->_raw += EPSILON * pow(2, 8);

	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	
	++*this;
	return (temp);
}

Fixed & Fixed::operator--(void)
{
	long	control;

	control = this->toInt() - EPSILON;
	if (control < -8388608)
		std::cerr << "\e[31m Warning: the raw bits are overflowed\e[0m" << std::endl;
	this->_raw -= EPSILON * pow(2, 8);

	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	
	--*this;
	return (temp);
}

/*
** --------------------------------- METHODS ----------------------------------
*/


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

Fixed & Fixed::min(Fixed & fixed1, Fixed & fixed2)
{
	if (fixed1 <= fixed2)
		return (fixed1);
	else
		return (fixed2);
}

Fixed	Fixed::min(Fixed const & fixed1, Fixed const & fixed2)
{
	if (fixed1 <= fixed2)
		return (Fixed(fixed1));
	else
		return (Fixed(fixed2));
}

Fixed & Fixed::max(Fixed & fixed1, Fixed & fixed2)
{
	if (fixed1 >= fixed2)
		return (fixed1);
	else
		return (fixed2);
}

Fixed	Fixed::max(Fixed const & fixed1, Fixed const & fixed2)
{
	if (fixed1 >= fixed2)
		return (Fixed(fixed1));
	else
		return (Fixed(fixed2));
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int	Fixed::getRawBits(void) const
{
	return (this->_raw);
}

void	Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
}

/* ************************************************************************** */