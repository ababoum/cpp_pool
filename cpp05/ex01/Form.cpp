/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:10:55 by mababou           #+#    #+#             */
/*   Updated: 2022/03/17 20:17:05 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(): _is_signed(false), _grade_to_sign(150), _grade_to_execute(150)
{
	std::cout << "\e[1;39;44m Form \e[0m ";
	std::cout << " \e[3mDefault constructor called\e[0m" << std::endl;
}

Form::Form( const Form & src ):_name(src.getName()), _is_signed(false), \
								_grade_to_sign(150), _grade_to_execute(150)
{
	std::cout << "\e[1;39;44m Form \e[0m ";
	std::cout << " \e[3mCopy constructor called\e[0m" << std::endl;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_exe): \
	_name(name), _is_signed(false), _grade_to_sign(grade_to_sign), \
	_grade_to_execute(grade_to_exe)
{
	std::cout << "\e[1;39;44m Form \e[0m ";
	std::cout << " \e[3mParameters constructor called\e[0m" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	std::cout << "\e[1;39;44m Form \e[0m ";
	std::cout << " \e[3mDestructor called\e[0m" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_is_signed = rhs.getIsSigned();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "The form " << i.getName() << " is ";
	if (!i.getIsSigned())
		o << "not ";
	o << "signed. The grade to sign it is " << i.getGradeSign();
	o << " and the grade to execute it is " << i.getGradeExe();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Form::beSigned(Bureaucrat signer)
{
	try
	{
		if (this->_grade_to_sign < signer.getGrade())
		{
			throw GradeTooLowException();
		}
		else
		{
			this->_is_signed = true;
			signer.signForm(true, this->_name);
		}
	}
	catch(GradeTooLowException e)
	{
		signer.signForm(false, this->_name);
	}	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		Form::getName(void) const
{
	return (this->_name);
}

bool			Form::getIsSigned(void) const
{
	return (this->_is_signed);
}

int				Form::getGradeSign(void) const
{
	return (this->_grade_to_sign);
}

int				Form::getGradeExe(void) const
{
	return (this->_grade_to_execute);
}

/* ************************************************************************** */