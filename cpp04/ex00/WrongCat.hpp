/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:33:09 by mababou           #+#    #+#             */
/*   Updated: 2022/03/29 19:24:07 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{

	public:

		WrongCat();
		WrongCat(WrongCat const &);
		~WrongCat();

		WrongCat &		operator=(WrongCat const &);
		
		void			makeSound(void) const;

	private:

};

std::ostream &			operator<<( std::ostream & o, WrongCat const & i );

#endif /* ******************************************************** WRONGCAT_H */