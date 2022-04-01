/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:11:40 by mababou           #+#    #+#             */
/*   Updated: 2022/04/01 21:18:25 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"


size_t	char_pos(const std::string& str, char c)
{
	size_t	i;

	for (i = 0; i < str.length(); i++)
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

int	char_count(const std::string& str, char c)
{
	size_t	i;
	int 	count;

	count = 0;
	for (i = 0; i < str.length(); i++)
	{
		if (str[i] == c)
			count++;
	}
	return (count);
}

static bool isInt(const std::string& str)
{
	double	d;
	size_t	i = 0;

    while (i < str.length()) {
        if ((str[i] == '-' || str[i] == '+') && i == 0 && str.length() != 1)
			i++;
		else {
			if (!std::isdigit(str[i]))
				return false;
			i++;
		}
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
	size_t	i = 0;

	if (!str.compare("-inff") || !str.compare("+inff") ||
		 !str.compare("nanf")) {
		return true;
	}
	
    while (i < str.length()) {
		if ((str[i] == '-' || str[i] == '+') && i == 0 && str.length() != 1)
			i++;
		else {
			if (!std::isdigit(str[i]) && str[i] != 'f' && str[i] != '.')
				return false;
			i++;
		}
    }
	if (char_count(str, 'f') > 1 || 
		char_count(str, '.') > 1 ||
		char_pos(str, 'f') != str.length() - 1 ||
		(char_count(str, 'f') == 1 && str.length() == 1) ||
		(char_count(str, '.') == 1 && str.length() < 4) ||
		(char_count(str, 'f') == 1 && char_count(str, '.') == 1 && 
			char_pos(str, 'f') - char_pos(str, '.') == 1))
		return false;
	std::istringstream iss (str);
	iss >> d;
	
	if (d > std::numeric_limits<float>::max() ||
	d < - std::numeric_limits<float>::max())
		return false;
	return true;
}

static bool isDouble(const std::string& str)
{
	double	d;
	size_t	i = 0;

	if (!str.compare("-inf") || !str.compare("+inf") ||
		 !str.compare("nan")) {
		return true;
	}
	
	while (i < str.length()) {
		if ((str[i] == '-' || str[i] == '+') && i == 0 && str.length() != 1)
			i++;
		else {
			if (!std::isdigit(str[i]) && str[i] != '.')
				return false;
			i++;
		}
    }
	if (char_count(str, '.') > 1 ||
		(char_count(str, '.') == 1 && str.length() < 3))
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
	// std::cout << "Detected type: " << _type << std::endl;
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
		if (!input.compare("+inff"))
			this->_float = std::numeric_limits<float>::infinity();
		else if (!input.compare("-inff"))
			this->_float = - std::numeric_limits<float>::infinity();
		else if (!input.compare("nanf"))
			this->_float = std::numeric_limits<float>::quiet_NaN();
		else {
			std::istringstream iss (input);
			iss >> this->_float;
		}
		return (FLOAT);	
	}
	else if (isDouble(input))
	{
		if (!input.compare("+inf"))
			this->_double = std::numeric_limits<double>::infinity();
		else if (!input.compare("-inf"))
			this->_double = - std::numeric_limits<double>::infinity();
		else if (!input.compare("nan"))
			this->_double = std::numeric_limits<double>::quiet_NaN();
		else {
			std::istringstream iss (input);
			iss >> this->_double;
		}
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
		else {
			output += "'";
			output += static_cast<char>(_c);
			output += "'";
		}
		break;
		
	case INT:
		if (_int >= 0 && _int <= 127 && (_int < 32 || _int > 126))
			output = "Non displayable";
		else if (_int < 0 || _int > 127)
			output = "Impossible";
		else {
			output += "'";
			output += static_cast<char>(_int);
			output += "'";
		}
		break;
	
	case FLOAT:
		if (_float >= 0 && _float <= 127 && (_float < 32 || _float > 126))
			output = "Non displayable";
		else if (_float < 0 || _float > 127 || _float != _float)
			output = "Impossible";
		else {
			output += "'";
			output += static_cast<char>(_float);
			output += "'";
		}
		break;
	
	case DOUBLE:
		if (_double >= 0 && _double <= 127 && (_double < 32 || _double > 126))
			output = "Non displayable";
		else if (_double < 0 || _double > 127 || _double != _double)
			output = "Impossible";
		else {
			output += "'";
			output += static_cast<char>(_double);
			output += "'";
		}
		break;
	
	default:
		output = "Impossible";
		break;
	}

	return (output);
}

std::string			Converter::toInt(void)
{
	std::string	output;
	std::stringstream iss_bis;

	switch (_type)
	{
	case CHAR:
		iss_bis << static_cast<int>(_c);
		output += iss_bis.str();
		break;
		
	case INT:
		iss_bis << _int;
		output += iss_bis.str();
		break;
	
	case FLOAT:
		if (_float > std::numeric_limits<int>::max() ||
			_float < std::numeric_limits<int>::min() ||
			_float != _float)
			output = "Impossible";
		else {
			iss_bis << static_cast<int>(_float);
			output += iss_bis.str();	
		}
		break;
	
	case DOUBLE:
		if (_double > std::numeric_limits<int>::max() ||
			_double < std::numeric_limits<int>::min() ||
			_double != _double)
			output = "Impossible";
		else {
			iss_bis << static_cast<int>(_double);
			output += iss_bis.str();	
		}
		break;
	
	default:
		output = "Impossible";
		break;
	}

	return (output);
}

std::string			Converter::toFloat(void)
{
	std::string	output;
	std::stringstream iss_bis;

	
	switch (_type)
	{
	case CHAR:
		iss_bis << std::fixed << std::setprecision(1) << static_cast<float>(_c);
		output += iss_bis.str();
		output += "f";
		// output += ".0f";
		break;
		
	case INT:
		iss_bis << std::fixed << std::setprecision(1) << static_cast<float>(_int);
		output += iss_bis.str();
		output += "f";
		// output += ".0f";
		break;
	
	case FLOAT:
		iss_bis << std::fixed << _float;
		output += iss_bis.str();
		// if (_float - std::floor(_float) == 0)
		// 	output += ".0";
		output += "f";
		break;
	
	case DOUBLE:
		if (_double > std::numeric_limits<float>::max())
			output = "+inff";
		else if (_double < - std::numeric_limits<float>::max())
			output = "-inff";
		else {
			iss_bis << std::fixed << static_cast<float>(_double);
			output += iss_bis.str();
			// if (_double - std::floor(_double) == 0)
			// 	output += ".0";
			output += "f";
		}
		break;
	
	default:
		output = "Impossible";
		break;
	}
	return (output);
}

std::string			Converter::toDouble(void)
{
	std::string	output;
	std::stringstream iss_bis;

	switch (_type)
	{
	case CHAR:
		iss_bis << std::fixed << std::setprecision(1) << static_cast<double>(_c);
		output += iss_bis.str();
		// output += ".0";
		break;
		
	case INT:
		iss_bis << std::fixed << std::setprecision(1) << static_cast<double>(_int);
		output += iss_bis.str();
		// output += ".0";
		break;
	
	case FLOAT:
		iss_bis << std::fixed << static_cast<double>(_float);
		output += iss_bis.str();
		// if (_float - std::floor(_float) == 0)
		// 	output += ".0";
		break;
	
	case DOUBLE:
		iss_bis << std::fixed << _double;
		output += iss_bis.str();
		// if (_double - std::floor(_double) == 0)
		// 	output += ".0";
		break;
	
	default:
		output = "Impossible";
		break;
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