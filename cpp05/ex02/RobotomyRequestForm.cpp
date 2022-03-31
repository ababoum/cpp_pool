/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:04:19 by mababou           #+#    #+#             */
/*   Updated: 2022/03/31 18:32:22 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(): Form()
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ): \
														Form(src)
{
	this->_target = src._target;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): \
	Form("Robotomy", _sign_grade, _exe_grade), _target(target)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
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

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned() || executor.getGrade() > getGradeExe())
		throw ConditionsNotRespectedException();
	else
	{
		std::cout << "*VRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR*" << std::endl;
		
		int prob;

		srand(time(NULL));
		prob = rand() % 2;
		
		if (prob == 0) {
			std::cout << this->_target << " has been successfully robotomized 🤖" <<std::endl;
		}
		else {
			std::cout << "The robotomization operation has failed 😡" <<std::endl;
		}
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/



/* ************************************************************************** */