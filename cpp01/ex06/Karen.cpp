/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:54:17 by mababou           #+#    #+#             */
/*   Updated: 2022/02/21 16:01:25 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void)
{
	std::cout << "\e[3m A Karen has called you!\e[0m" << std::endl;
}

Karen::~Karen(void)
{
	std::cout << "\e[3m Karen left.\e[0m" << std::endl;
}

void	Karen::complain(std::string level, int filter) const
{
	if (level == "DEBUG" && filter <= DEBUG_LVL)
		this->_debug();
	if (level == "INFO" && filter <= INFO_LVL)
		this->_info();
	if (level == "WARNING" && filter <= WARNING_LVL)
		this->_warning();
	if (level == "ERROR" && filter <= ERROR_LVL)
		this->_error();
	
}

void	Karen::display_filter(int filter) const
{
	if (filter == DEBUG_LVL)
		std::cout << "[ DEBUG ]" << std::endl;
	if (filter == INFO_LVL)
		std::cout << "[ INFO ]" << std::endl;
	if (filter == WARNING_LVL)
		std::cout << "[ WARNING ]" << std::endl;
	if (filter == ERROR_LVL)
		std::cout << "[ ERROR ]" << std::endl;
}

int	Karen::convert_filter(std::string level) const
{
	if (level == "DEBUG")
		return DEBUG_LVL;
	else if (level == "INFO")
		return INFO_LVL;
	else if (level == "WARNING")
		return WARNING_LVL;
	else if (level == "ERROR")
		return ERROR_LVL;
	else
		return (42);
}


void	Karen::_debug(void) const
{
	this->display_filter(DEBUG_LVL);
	std::cout << "\"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do !\"" << std::endl << std::endl;;
}

void	Karen::_info(void) const
{
	this->display_filter(INFO_LVL);
	std::cout << "\"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger!" << std::endl;
	std::cout<< "If you did, I wouldn't be asking for more!\"" << std::endl << std::endl;
}

void	Karen::_warning(void) const
{
	this->display_filter(WARNING_LVL);
	std::cout << "\"I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month.\"" << std::endl << std::endl;
}

void	Karen::_error(void) const
{
	this->display_filter(ERROR_LVL);
	std::cout << "\"This is unacceptable! I want to speak to the manager now.\"" << std::endl << std::endl;
}