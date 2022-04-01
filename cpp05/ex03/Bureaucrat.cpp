/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:04:01 by mababou           #+#    #+#             */
/*   Updated: 2022/04/01 18:56:51 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(): _grade(_lowestGrade)
{
	std::cout << std::setw(30);
	std::cout << "\e[1;30;43m Bureaucrat \e[0m ";
	std::cout << "\e[3mDefault constructor called\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(_lowestGrade)
{
	std::cout << std::setw(30);
	std::cout << "\e[1;30;43m Bureaucrat \e[0m ";
	std::cout << "\e[3mName constructor called\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << std::setw(30);
	std::cout << "\e[1;30;43m Bureaucrat \e[0m ";
	std::cout << "\e[3mName & Grade constructor called\e[0m" << std::endl;
	
	if (this->_grade > _lowestGrade)
		throw GradeTooLowException();
	else if (this->_grade < _highestGrade)
		throw GradeTooHighException();	
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ): _name(src.getName()), \
													_grade(src.getGrade())
{
	std::cout << std::setw(30);
	std::cout << "\e[1;30;43m Bureaucrat \e[0m ";
	std::cout << "\e[3mCopy constructor called\e[0m" << std::endl;
	
	if (this->_grade > _lowestGrade)
		throw GradeTooLowException();
	else if (this->_grade < _highestGrade)
		throw GradeTooHighException();	
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	std::cout << std::setw(30);
	std::cout << "\e[1;30;43m Bureaucrat \e[0m ";
	std::cout << "\e[3mDestructor called\e[0m" << std::endl;
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
	if (this->_grade == _highestGrade)
		throw GradeTooHighException();
	else
		this->_grade -= 1;
}

void		Bureaucrat::gradeDecrement(void)
{
	if (this->_grade == _lowestGrade)
		throw GradeTooLowException();
	else
		this->_grade += 1;
}

void		Bureaucrat::signForm(bool isSigned, std::string form_name)
{
	if (isSigned)
	{
		std::cout << this->_name << " signed " << form_name << std::endl;
	}
	else
	{
		std::cout << this->_name << " couldn't sign " << form_name;
		std::cout << " because their grade is not high enough" << std::endl;
	}
}

void		Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}	
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