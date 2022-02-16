/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:44:24 by mababou           #+#    #+#             */
/*   Updated: 2022/02/16 18:02:13 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include <iostream>
#include "Weapon.hpp"

class	HumanB {
	
public:

	HumanB(std::string name);
	~HumanB(void);	

	void		setName(std::string);
	std::string	getName(void) const;
	void		setWeapon(Weapon);
	Weapon		getWeapon(void) const;
	void		attack(void);

private:

	std::string	_name;
	Weapon		_weapon;
};

#endif