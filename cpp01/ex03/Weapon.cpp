/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:54:17 by mababou           #+#    #+#             */
/*   Updated: 2022/02/16 18:54:32 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = new std::string(type);
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

void	Weapon::setType(std::string type)
{
	delete this->_type;
	this->_type = new std::string(type);
}

std::string	*Weapon::getType(void) const
{
	return this->_type;
}
