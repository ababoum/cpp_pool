/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:55:30 by mababou           #+#    #+#             */
/*   Updated: 2022/03/24 21:10:12 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "A zombie has appeared." << std::endl;
}

Zombie::Zombie(std::string name): _name(name)
{
	std::cout << "A zombie has appeared." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "The zombie " << this->_name << " is destroyed." << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

std::string	Zombie::getName(void) const
{
	return this->_name;
}
