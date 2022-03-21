/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:11:40 by mababou           #+#    #+#             */
/*   Updated: 2022/03/21 20:38:35 by mababou          ###   ########.fr       */
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
	this->_type = _detect_type(this->_input);
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

size_t	char_pos(const std::string& str, char c)
{
	size_t	i;

	for (i = 0; str.length(); i++)
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

int	char_count(const std::string& str, char c)
{
	int	i;
	int count;

	count = 0;
	for (i = 0; str.length(); i++)
	{
		if (str[i] == c)
			count++;
	}
	return (count);
}

static bool isInt(const std::string& str)
{
	double	d;
	size_t	i;
	
    for (i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i]))
			return false;
    }
	std::istringstream iss (str);
	iss >> d;
	
	if (d > std::numeric_limits<int>::max() ||
	d < std::numeric_limits<int>::min())
		return false;
	return true;
}

static bool isFloat(const std::string& str)
{
	double	d;
	size_t	i;
	
    for (i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i]) && str[i] != 'f' && str[i] != '.')
			return false;
    }
	if (char_count(str, 'f') > 1 || char_count(str, '.') > 1 ||
	char_pos(str, 'f') != str.length() - 1 ||
	(char_count(str, 'f') == 1 && str.length() == 1) ||
	(char_count(str, '.') == 1 && str.length() < 4) ||
	(char_count(str, 'f') == 1 && char_count(str, '.') == 1 && 
		char_pos(str, 'f') - char_pos(str, '.') == 1))
		return false;
	std::istringstream iss (str);
	iss >> d;
	
	if (d > std::numeric_limits<float>::max() ||
	d < std::numeric_limits<float>::min())
		return false;
	return true;
}

static bool isDouble(const std::string& str)
{
	double	d;
	size_t	i;
	
    for (i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i]) && str[i] != 'f' && str[i] != '.')
			return false;
    }
	if (char_count(str, 'f') > 1 || char_count(str, '.') > 1 ||
	(char_count(str, 'f') == 1 && str.length() == 1) ||
	(char_count(str, '.') == 1 && str.length() < 4) ||
	(char_count(str, 'f') == 1 && char_count(str, '.') == 1 && 
		(char_pos(str, 'f') - char_pos(str, '.') == 1 ||
		char_pos(str, 'f') - char_pos(str, '.') < 0)))
		return false;
	std::istringstream iss (str);
	iss >> d;
	
	return true;
}

std::string			Converter::_detect_type(std::string input)
{
	if (input.length() == 0)
	{
		this->_c = 0;
		return ("char");
	}
	else if (input.length() == 1)
	{
		std::istringstream iss (input);
		iss >> this->_c;
		return ("char");
	}
	else if (isInt(input))
	{
		std::istringstream iss (input);
		iss >> this->_int;
		return ("int");		
	}
	else if (isFloat(input))
	{
		std::istringstream iss (input);
		iss >> this->_float;
		return ("float");	
	}
	else if (isDouble(input))
	{
		std::istringstream iss (input);
		iss >> this->_double;
		return ("double");
	}
	else
	{
		return ("nan");
	}
}

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

std::string			Converter::toInt(void)
{
	double		d;
	std::string	output;
	int			nb;
	
	std::istringstream iss (this->_input);
	iss >> d;

	if (!(this->_input.compare("nan") && this->_input.compare("nanf") &&
		this->_input.compare("+inf") && this->_input.compare("+inff") &&
		this->_input.compare("-inf") && this->_input.compare("-inff")) ||
		d > std::numeric_limits<int>::max() ||
		d < std::numeric_limits<int>::min())
		output = "impossible";
	else
	{
		nb = static_cast<int>(d);
		std::stringstream iss_bis;
		iss_bis << nb;
		output += iss_bis.str();
	}
	return (output);
}

std::string			Converter::toFloat(void)
{
	double		d;
	std::string	output;
	float		nb;
	
	std::istringstream iss (this->_input);
	iss >> d;
	if (!this->_input.compare("nan") || !this->_input.compare("nanf"))
		output += "nanf";
	else if (!this->_input.compare("+inf") || !this->_input.compare("+inff") ||
	d > std::numeric_limits<float>::max())
		output += "+inff";
	else if (!this->_input.compare("+inf") || !this->_input.compare("+inff") ||
	d < std::numeric_limits<float>::min())
		output += "-inff";
	else
	{
		nb = static_cast<float>(d);
		std::stringstream iss_bis;
		iss_bis << nb;
		output += iss_bis.str();		
	}
	return (output);
}

std::string			Converter::toDouble(void)
{
	double		d;
	std::string	output;
	double		nb;
	
	std::istringstream iss (this->_input);
	iss >> d;
	if (!this->_input.compare("nan") || !this->_input.compare("nanf"))
		output += "nan";
	else if (!this->_input.compare("+inf") || !this->_input.compare("+inff") ||
	d >= std::numeric_limits<double>::max())
		output += "+inf";
	else if (!this->_input.compare("+inf") || !this->_input.compare("+inff") ||
	d <= std::numeric_limits<float>::min())
		output += "-inf";
	else
	{
		nb = static_cast<double>(d);
		std::stringstream iss_bis;
		iss_bis << nb;
		output += iss_bis.str();		
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