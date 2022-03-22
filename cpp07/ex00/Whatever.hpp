/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:25:51 by mababou           #+#    #+#             */
/*   Updated: 2022/03/22 17:05:42 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template< typename T >
void	swap(T & a, T & b) {
	T c;
	
	c = a;
	a = b;
	b = c;
};

template< typename T >
T const & min(T const & a, T const & b) {
	return ( a > b ? b : a);
};

template< typename T >
T const & max(T const & a, T const & b) {
	return ( a > b ? a : b);
}

#endif /* ******************************************************** WHATEVER_H */