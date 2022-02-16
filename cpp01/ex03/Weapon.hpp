/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:30:10 by mababou           #+#    #+#             */
/*   Updated: 2022/02/16 18:53:52 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>

class	Weapon {
	
public:

	Weapon(std::string type);
	~Weapon(void);

	void		setType(std::string);
	std::string	*getType(void) const;

private:

	std::string	*_type;
};

#endif