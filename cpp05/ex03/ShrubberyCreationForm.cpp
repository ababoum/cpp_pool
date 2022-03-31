/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:04:19 by mababou           #+#    #+#             */
/*   Updated: 2022/03/31 19:20:50 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(): Form("Shrubbery", 150, 150)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ): \
														Form(src)
{
	this->_target = src._target;
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

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
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

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned() || executor.getGrade() > getGradeExe())
		throw ConditionsNotRespectedException();
	else
	{
		std::ofstream	file;
		std::string		filename;

		filename = this->_target + "_shrubbery";
		
		file.open(filename.data(), std::ofstream::out | std::ofstream::trunc);
		if (!file) {
			std::cerr << "\e[31mAn error occured while creating the output file\e[0m" << std::endl;
			return ;
		}
		file << TREE;
		file << TREE;
		file << TREE;
		file.close();
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/



/* ************************************************************************** */