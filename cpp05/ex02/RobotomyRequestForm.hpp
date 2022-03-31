/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:04:19 by mababou           #+#    #+#             */
/*   Updated: 2022/03/31 16:28:11 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include <cstdlib>

class RobotomyRequestForm: public Form
{

	public:

		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm();

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

		void			execute(Bureaucrat const & executor) const;

	private:
		std::string			_target;
		static const int	_sign_grade = 72;
		static const int	_exe_grade = 45;

};

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */