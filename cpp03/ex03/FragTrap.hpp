/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:41:34 by mababou           #+#    #+#             */
/*   Updated: 2022/02/23 15:08:09 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
# define FragTrap_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:

		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const & src);
		~FragTrap();

		FragTrap &	operator=(FragTrap const & rhs);

		void		highFivesGuys(void) const;
		void		attack(const std::string& target);

};

std::ostream &	operator<<( std::ostream & o, FragTrap const & i );

#endif /* ******************************************************** FragTrap_HPP */