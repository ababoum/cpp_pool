/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:04:42 by mababou           #+#    #+#             */
/*   Updated: 2022/03/28 17:33:06 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "===============================" << std::endl;

	Fixed const c( Fixed(500.05f) / Fixed(5));
	Fixed const d( Fixed(500.05f) - Fixed(5));

	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << Fixed::max( c, d ) << std::endl;
	std::cout << Fixed::min( c, d ) << std::endl;
	

	std::cout << "===============================" << std::endl;
	
	Fixed const e( Fixed(500.05f) / Fixed(0));

	std::cout << e << std::endl;
	
	return 0;
}