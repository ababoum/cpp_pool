/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:54:17 by mababou           #+#    #+#             */
/*   Updated: 2022/02/21 16:01:25 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

typedef	void (Harl::*Action)(void);


Harl::Harl(std::string filter)
{
	std::cout << "\e[3m A Harl has called you!\e[0m" << std::endl;
	this->_filter = Harl::convert_filter(filter);
}

Harl::~Harl(void)
{
	std::cout << "\e[3m Harl left.\e[0m" << std::endl;
}

void	Harl::complain(std::string level)
{
	int lvl;
	Action action[] = { &Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};


	lvl = Harl::convert_filter(level);
	if (lvl < this->_filter)
		return ;

	switch (lvl)
	{
		case (DEBUG_LVL):
		((*this).*(action[lvl]))();
		break ;

		case (INFO_LVL):
		((*this).*(action[lvl]))();
		break ;

		case (WARNING_LVL):
		((*this).*(action[lvl]))();
		break ;

		case (ERROR_LVL):
		((*this).*(action[lvl]))();
		break ;

		default :
		break ; 

	}
}

void	Harl::_display_filter(int filter) const
{
	switch (filter)
	{
		case DEBUG_LVL:
			std::cout << "[ DEBUG ]" << std::endl;
			break ;
		
		case INFO_LVL:
			std::cout << "[ INFO ]" << std::endl;
			break ;
		
		case WARNING_LVL:
			std::cout << "[ WARNING ]" << std::endl;
			break ;
		
		case ERROR_LVL:
			std::cout << "[ ERROR ]" << std::endl;
			break ;
		
		default:
			break ;
	}
}

int	Harl::convert_filter(std::string level) const
{
	std::string complaintLevels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int	i;

	for (i = 0; i < 4; i++) {
		if (!level.compare(complaintLevels[i]))
			return (i);
	}
	return (42);
}

int		Harl::getFilter(void) const
{
	return (this->_filter);
}


void	Harl::_debug(void)
{
	this->_display_filter(DEBUG_LVL);
	std::cout << "\"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do !\"" << std::endl << std::endl;;
}

void	Harl::_info(void)
{
	this->_display_filter(INFO_LVL);
	std::cout << "\"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger!" << std::endl;
	std::cout<< "If you did, I wouldn't be asking for more!\"" << std::endl << std::endl;
}

void	Harl::_warning(void)
{
	this->_display_filter(WARNING_LVL);
	std::cout << "\"I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month.\"" << std::endl << std::endl;
}

void	Harl::_error(void)
{
	this->_display_filter(ERROR_LVL);
	std::cout << "\"This is unacceptable! I want to speak to the manager now.\"" << std::endl << std::endl;
}