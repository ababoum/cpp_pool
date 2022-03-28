/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:41:34 by mababou           #+#    #+#             */
/*   Updated: 2022/03/28 20:52:35 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:

		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &);
		~ScavTrap();

		ScavTrap &	operator=(ScavTrap const & rhs);

		void		guardGate(void) const;
		void		attack(const std::string& target);
		
		static const unsigned int	init_hit_points = 100;
		static const unsigned int	init_energy_points = 50;
		static const unsigned int	init_attack_damage = 20;

};

std::ostream &	operator<<( std::ostream & o, ScavTrap const & i );

#endif /* ******************************************************** SCAVTRAP_H */