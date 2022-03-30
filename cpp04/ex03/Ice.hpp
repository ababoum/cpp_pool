/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:10:45 by mababou           #+#    #+#             */
/*   Updated: 2022/03/30 18:33:50 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Ice_HPP
# define Ice_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Ice: public AMateria
{

	public:

		Ice();
		Ice(Ice const & src);
		~Ice();

		Ice &		operator=( Ice const & rhs );

		Ice* 		clone() const;
		void 		use(ICharacter& target);
};

#endif /* ************************************************************ Ice_H */