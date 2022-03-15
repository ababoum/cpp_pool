/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:54:17 by mababou           #+#    #+#             */
/*   Updated: 2022/03/15 16:16:16 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

typedef	void (Karen::*Action)(void);

Karen::Karen(void)
{
	std::cout << "\e[3m A Karen has called you!\e[0m" << std::endl;
}

Karen::~Karen(void)
{
	std::cout << "\e[3m Karen left.\e[0m" << std::endl;
}

void	Karen::complain(std::string level)
{
	Action action[] = { &Karen::_debug, &Karen::_info, &Karen::_warning, &Karen::_error};
	std::string input[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i;

	i = 0;
	while (i < 4)
	{
		if (level == input[i])
			((*this).*(action[i]))();
		i++;
	}
}

void	Karen::_debug(void)
{
	std::cout << "\"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do !\"" << std::endl;
}

void	Karen::_info(void)
{
	std::cout << "\"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger!" << std::endl;
	std::cout<< "If you did, I wouldn't be asking for more!\"" << std::endl;
}

void	Karen::_warning(void)
{
	std::cout << "\"I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month.\"" << std::endl;
}

void	Karen::_error(void)
{
	std::cout << "\"This is unacceptable! I want to speak to the manager now.\"" << std::endl;
}