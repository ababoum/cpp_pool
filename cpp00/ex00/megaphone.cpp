/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:55:35 by mababou           #+#    #+#             */
/*   Updated: 2022/02/14 16:03:30 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	to_upper(char c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

int	main(int ac, char **av)
{
	int i = 0;
	int j = 0;
	
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		while (i < ac - 1)
		{
			j = 0;
			while (av[i + 1][j])
				std::cout << to_upper(av[i + 1][j++]);
			i++;
		}
		std::cout << std::endl;	
	}
}
