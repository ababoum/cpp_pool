/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:25:51 by mababou           #+#    #+#             */
/*   Updated: 2022/04/04 12:21:37 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template<typename T>
class Array {
	
	public:

		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char * what() const throw() {
					return ("\e[41m The selected index is out of range\e[0m");
				}		
		};

		class NegativeSizeException : public std::exception
		{
			public:
				virtual const char * what() const throw() {
					return ("\e[41m The input size is invalid \e[0m");
				}		
		};
		
		Array (void): _array(NULL), _size(0) {}

		Array (unsigned int n)
		{
			if (n < 0)
				throw NegativeSizeException();
			else
			{
				_array = new T[n];
				_size = n;
			}
		}

		Array (Array & src): _array(new T[src._size]), _size(src._size)
		{
			unsigned int i;
			
			for (i = 0; i < src._size; i++) {
				this->_array[i] = src._array[i];
			}
		};
		
		~Array()
		{
			if (this->_size > 0)
				delete [] this->_array;
		};

		T	&	operator[]( unsigned int index ) const {
			if (index >= 0 && index < _size)
				return (this->_array[index]);
			else
				throw OutOfRangeException();
		}

		T 	&	operator=( Array & src ) const {
			unsigned int i;

			for (i = 0; i < src._size; i++) {
				this->_array[i] = src._array[i];
			}
			this->_size = src._size;
		}

		unsigned int size(void) const {
			return (this->_size);
		}

	private:
		T				*_array;
		unsigned int	_size;

	
};

#endif /* ************************************************************ ITER_H */