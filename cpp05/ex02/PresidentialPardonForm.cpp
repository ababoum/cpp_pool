/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:26:33 by mababou           #+#    #+#             */
/*   Updated: 2022/03/31 18:32:26 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm(): Form()
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ): \
														Form(src)
{
	this->_target = src._target;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): \
	Form("Shrubbery", _sign_grade, _exe_grade), _target(target)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs._target;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned() || executor.getGrade() > getGradeExe())
		throw ConditionsNotRespectedException();
	else
	{
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/



/* ************************************************************************** */