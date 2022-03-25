/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:44:24 by mababou           #+#    #+#             */
/*   Updated: 2022/03/25 13:56:38 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanB {
	
public:

	HumanB(void);
	HumanB(std::string name);
	~HumanB(void);	

	void		setName(std::string);
	std::string	getName(void) const;
	void		setWeapon(Weapon &);
	Weapon		*getWeapon(void) const;
	void		attack(void);

private:

	std::string	_name;
	Weapon		*_weapon;
};

#endif