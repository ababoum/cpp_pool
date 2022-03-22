/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:26:04 by mababou           #+#    #+#             */
/*   Updated: 2022/03/22 17:46:18 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "iter.hpp"

void	putnbr(int nb) {
		std::cout << nb << std::endl;
};
	
void	putstr(std::string str) {
	std::cout << str << std::endl;
};

int	main(void)
{
	

	int lst_int[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::string lst_str[5] = {"one", "two", "three", "four", "five"};

	::iter(lst_int, 10, putnbr);
	::iter(lst_str, 5, putstr);

	return (0);
}