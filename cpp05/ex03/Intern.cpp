/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:09:36 by mababou           #+#    #+#             */
/*   Updated: 2022/03/31 20:40:41 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

typedef	Form* (Intern::*Creation)(std::string);

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	std::cout << std::setw(30);
	std::cout << "\e[1;30;104m Intern \e[0m ";
	std::cout << "\e[3mDefault constructor called\e[0m" << std::endl;
}

Intern::Intern( const Intern & src )
{
	(void)src;
	std::cout << std::setw(30);
	std::cout << "\e[1;30;104m Intern \e[0m ";
	std::cout << "\e[3mCopy constructor called\e[0m" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
	std::cout << std::setw(30);
	std::cout << "\e[1;30;104m Intern \e[0m ";
	std::cout << "\e[3mDestructor called\e[0m" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	(void)i;
	o << "Anonymous intern";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Form	*Intern::makeForm(std::string form_name, std::string target)
{
	std::string	form_list[] = {"Shrubbery", "Robotomy", \
									"Presidential Pardon", ""};

	

	Creation creation_list[] = {
		&Intern::_makeShrubbery,
		&Intern::_makeRobotomy,
		&Intern::_makePardon
	};

	int index = 0;
	while (!form_list[index].empty()) {
		if (!form_name.compare(form_list[index])) {
			return (((*this).*(creation_list[index]))(target));
		}
		index++;
	}
	throw InexistantFormException();
	return (0);
}

Form	*Intern::_makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::_makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form	*Intern::_makePardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */