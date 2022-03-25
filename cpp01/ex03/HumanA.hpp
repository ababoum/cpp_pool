/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:44:24 by mababou           #+#    #+#             */
/*   Updated: 2022/03/25 13:51:48 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanA {
	
public:

	HumanA(Weapon & weapon);
	HumanA(std::string name, Weapon & weapon);
	~HumanA(void);	

	void		setName(std::string);
	std::string	getName(void) const;
	void		setWeapon(Weapon &);
	Weapon		getWeapon(void) const;
	void		attack(void);

private:

	std::string	_name;
	Weapon		& _weapon;
};

#endif