std::ostream &			operator<<( std::ostream & o, ICharacter const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:59:30 by mababou           #+#    #+#             */
/*   Updated: 2022/03/30 15:09:44 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class AMateria
{
	protected:
		std::string		type_;
		
	public:
	
		AMateria(std::string const & type);
		virtual ~AMateria();

		std::string const &	getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		virtual void 		use(ICharacter& target);

};

std::ostream &			operator<<( std::ostream & o, AMateria const & i );

#endif /* ******************************************************** AMATERIA_H */