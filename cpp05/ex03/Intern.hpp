/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:09:36 by mababou           #+#    #+#             */
/*   Updated: 2022/03/31 20:34:58 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"



class Intern
{

	public:

		class InexistantFormException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("\e[41m The intern cannot find any form with the given name \e[0m");
				}			
		};

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );

		Form	*makeForm(std::string form_name, std::string target);
	
	private:

		Form	*_makeShrubbery(std::string target);
		Form	*_makeRobotomy(std::string target);
		Form	*_makePardon(std::string target);

};

std::ostream &			operator<<( std::ostream & o, Intern const & i );

#endif /* ********************************************************** INTERN_H */