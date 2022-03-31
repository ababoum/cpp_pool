/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:26:33 by mababou           #+#    #+#             */
/*   Updated: 2022/03/31 18:52:20 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class PresidentialPardonForm: public Form
{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm( PresidentialPardonForm const & src );
		~PresidentialPardonForm();

		PresidentialPardonForm & operator=( PresidentialPardonForm const & rhs );

		void			execute(Bureaucrat const & executor) const;

	private:
		std::string			_target;
		static const int	_sign_grade = 25;
		static const int	_exe_grade = 5;

};

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */