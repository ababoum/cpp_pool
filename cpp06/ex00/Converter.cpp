/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:11:40 by mababou           #+#    #+#             */
/*   Updated: 2022/03/31 21:08:37 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"


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
        if (!std::isdigit(str[i]) && str[i] != '-' && i != 0)
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

int			Converter::_detect_type(std::string input)
{
	if (input.length() == 0)
	{
		this->_int = 0;
		return (INT);
	}
	else if (input.length() == 1)
	{
		if (input.at(0) >= '0' && input.at(0) <= '9') {
			std::istringstream iss (input);
			iss >> this->_int;
			return (INT);
		}
		else {
			std::istringstream iss (input);
			iss >> this->_c;
			return (CHAR);
		}
	}
	else if (isInt(input))
	{
		std::istringstream iss (input);
		iss >> this->_int;
		return (INT);		
	}
	else if (isFloat(input))
	{
		std::istringstream iss (input);
		iss >> this->_float;
		return (FLOAT);	
	}
	else if (isDouble(input))
	{
		std::istringstream iss (input);
		iss >> this->_double;
		return (DOUBLE);
	}
	else
	{
		return (OTHER);
	}
}

std::string			Converter::toChar(void)
{
	std::string	output;

	switch (_type)
	{
	case CHAR:
		if (_c < 32 || _c > 126)
			output = "Non displayable";
		else
			output += static_cast<char>(_c);
		break;
		
	case INT:
		if (_int >= 0 && _int <= 127 && (_int < 32 || _int > 126))
			output = "Non displayable";
		else if (_int < 0 || _int > 127)
			output = "Impossible";
		else
			output += static_cast<char>(_int);
		break;
	
	default:
		break;
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