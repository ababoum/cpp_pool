/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:51:28 by mababou           #+#    #+#             */
/*   Updated: 2022/04/05 09:05:30 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <deque>

class NotFoundException : public std::exception
{
	public:
		virtual const char * what() const throw() {
			return ("\e[41m The searched value has no occurence in the container \e[0m");
		}		
};

template <typename T>
typename T::iterator easyfind(T & container, int n) {
	
	typename T::iterator pos = std::find(container.begin(), container.end(), n);
	
	if (pos == container.end())
		throw NotFoundException();
	return (pos);
}

template <typename T>
void	displayIterator(T it, T end)
{
	if (it != end)
		std::cout << "First occurence found: " << *it << std::endl;
	else
		std::cout << "No occurence found for given value" << std::endl;
}
