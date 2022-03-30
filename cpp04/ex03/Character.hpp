/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:38:41 by mababou           #+#    #+#             */
/*   Updated: 2022/03/30 20:11:13 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class Character: public ICharacter
{

	public:

		Character();
		Character(std::string name);
		Character( Character const & src );
		~Character();

		Character &		operator=( Character const & rhs );

		std::string const & getName() const;
		void 				equip(AMateria* m);
		void 				unequip(int idx);
		void 				use(int idx, ICharacter& target);
		// AMateria			**getInventory(void);

	private:
		AMateria		*_inventory[4];
		int				_cursor;
		std::string		_name;

};

std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */