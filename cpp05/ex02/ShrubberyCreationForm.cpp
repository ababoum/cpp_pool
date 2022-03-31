/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:04:19 by mababou           #+#    #+#             */
/*   Updated: 2022/03/31 12:19:07 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

# define TREE "       _-_\
    /~~   ~~\\\
 /~~         ~~\\\
{               }\
 \\  _-     -_  /\
   ~  \\ //  ~\
_- -   | | _- _\
  _ -  | |   -_\
      // \\\\"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(): Form()
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ): \
														Form(src)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): \
	Form("Shrubbery", _sign_grade, _exe_grade), _target(target)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned() || executor.getGrade() > this->getGradeExe())
		throw ConditionsNotRespectedException();
	else
	{
		std::ofstream	file;
		
		file.open(this->_target + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
		if (!file) {
			std::cerr << "\e[31mAn error occured while creating the output file\e[0m" << std::endl;
			return ;
		}
		file << TREE;
		file.close();
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		ShrubberyCreationForm::getName(void) const
{
	return (this->_name);
}

bool			ShrubberyCreationForm::getIsSigned(void) const
{
	return (this->_is_signed);
}

int				ShrubberyCreationForm::getGradeSign(void) const
{
	return (this->_grade_to_sign);
}

int				ShrubberyCreationForm::getGradeExe(void) const
{
	return (this->_grade_to_execute);
}


/* ************************************************************************** */