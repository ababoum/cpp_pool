/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:55:46 by mababou           #+#    #+#             */
/*   Updated: 2022/03/24 21:08:23 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
	
public:

	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);	

	void		announce(void) const;
	void		setName(std::string name);
	std::string	getName(void) const;
	
private:

	std::string	_name;
};

void 	randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif