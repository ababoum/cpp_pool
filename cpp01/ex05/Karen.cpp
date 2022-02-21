/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:54:17 by mababou           #+#    #+#             */
/*   Updated: 2022/02/21 13:21:57 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void)
{
	std::cout << "A Karen has called you!" << std::endl;
}

Karen::~Karen(void)
{
	std::cout << "Karen left." << std::endl;
}

void	Karen::complain(std::string level)
{
	void	(*fn)(void);

	if (level == "DEBUG")
		this->_debug();
	if (level == "INFO")
		this->_info();
	if (level == "WARNING")
		this->_warning();
	if (level == "ERROR")
		this->_error();
}

void	Karen::_debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void	Karen::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void	Karen::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Karen::_error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}