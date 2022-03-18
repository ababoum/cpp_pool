/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:04:01 by mababou           #+#    #+#             */
/*   Updated: 2022/03/18 13:41:52 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(): _grade(150)
{
	std::cout << "\e[1;30;43m Bureaucrat \e[0m ";
	std::cout << " \e[3mDefault constructor called\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(150)
{
	std::cout << "\e[1;30;43m Bureaucrat \e[0m ";
	std::cout << " \e[3mName constructor called\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << "\e[1;30;43m Bureaucrat \e[0m ";
	std::cout << " \e[3mName & Grade constructor called\e[0m" << std::endl;

	if (this->_grade > 150)
		throw GradeTooLowException();
	else if (this->_grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ): _name(src.getName())
{
	std::cout << "\e[1;30;43m Bureaucrat \e[0m ";
	std::cout << " \e[3mCopy constructor called\e[0m" << std::endl;
	_grade = src.getGrade();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[1;30;43m Animal\e[0m ";
	std::cout << " \e[3mDestructor called\e[0m" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		Bureaucrat::gradeIncrement(void)
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	else
		this->_grade -= 1;
}

void		Bureaucrat::gradeDecrement(void)
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	else
		this->_grade += 1;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}


/* ************************************************************************** */