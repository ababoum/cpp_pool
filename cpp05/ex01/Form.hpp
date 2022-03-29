/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:10:55 by mababou           #+#    #+#             */
/*   Updated: 2022/03/29 16:06:59 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
	public:

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("\e[41m The grade associated with the Form is too high (< 1)\e[0m");
				}			
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("\e[41m The grade associated with the Form is too low (> 150)\e[0m");
				}			
		};

		Form();
		Form( Form const & src );
		Form(std::string name, int grade_to_sign, int grade_to_exe);
		~Form();

		Form &		operator=( Form const & rhs );

		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		int				getGradeSign(void) const;
		int				getGradeExe(void) const;

		void			beSigned(Bureaucrat signer);

	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_to_sign;
		const int			_grade_to_execute;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */
