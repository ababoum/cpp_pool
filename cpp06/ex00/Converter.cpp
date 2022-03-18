/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:11:40 by mababou           #+#    #+#             */
/*   Updated: 2022/03/18 17:06:28 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Converter::Converter()
{
}

Converter::Converter(std::string input): _input(input)
{
}

Converter::Converter( const Converter & src )
{
	this->_input = src._input;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Converter::~Converter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Converter &				Converter::operator=( Converter const & rhs )
{
	if ( this != &rhs )
	{
		this->_input = rhs.getInput();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Converter const & i )
{
	o << i.getInput();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string			Converter::toChar(void)
{
	double		d;
	std::string	output;
	int			c;
	
	std::istringstream iss (this->_input);
	iss >> d;

	if (!(this->_input.compare("nan") && this->_input.compare("nanf") && \
		this->_input.compare("+inf") && this->_input.compare("+inff") && \
		this->_input.compare("-inf") && this->_input.compare("-inff")))
		output = "impossible";
	else
	{
		c = static_cast<int>(d);
		if (c < 32 || c > 126)
			output = "Non displayable";
		else
			output += static_cast<char>(c);
	}
	return (output);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		Converter::getInput(void) const
{
	return (this->_input);
}

/* ************************************************************************** */