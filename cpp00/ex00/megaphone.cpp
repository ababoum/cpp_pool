/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:55:35 by mababou           #+#    #+#             */
/*   Updated: 2022/03/24 18:57:27 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string	str_toupper(std::string & str)
{
	unsigned long	i;
	std::string		upper;

	for (i = 0; i < str.length(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z')
			upper += std::toupper(str[i]);
		else
			upper += str[i];
	}
	return (upper);
}

int	main(int ac, char **av)
{
	int i = 0;
	
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		while (i < ac - 1)
		{
			std::string arg(av[i + 1]);
			std::cout << str_toupper(arg);
			i++;
		}
		std::cout << std::endl;	
	}
}
