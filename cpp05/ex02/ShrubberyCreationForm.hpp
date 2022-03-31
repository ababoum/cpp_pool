/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:04:19 by mababou           #+#    #+#             */
/*   Updated: 2022/03/31 12:24:43 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm: public Form
{

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm();

		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );

		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		int				getGradeSign(void) const;
		int				getGradeExe(void) const;

		void			execute(Bureaucrat const & executor) const;

	private:
		std::string		_target;
		static int		_exe_grade = 137;
		static int		_sign_grade = 145;

};

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */