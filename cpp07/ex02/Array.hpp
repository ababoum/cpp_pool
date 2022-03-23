/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:25:51 by mababou           #+#    #+#             */
/*   Updated: 2022/03/23 12:03:28 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template< typename T >
class Array {
	
	public:
		Array (void) {
			this->_array = 0;
			this->_size = 0;
		}
	void	Array::Array (unsigned int n) {
		unsigned int	i;
		
		this->_array = new T(n);
		for (i = 0; i < n; i++) {
			this->_array[i] = 0;
	}
	this->_size = n;
}

		~Array (void);

		Array &		operator[]( unsigned int index );

		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char * what() const throw() {
					return ("\e[41m The selected index is out of range \e[0m");
				}		
		};

	private:
		T				*_array;
		unsigned int	_size;

	
};

#endif /* ************************************************************ ITER_H */