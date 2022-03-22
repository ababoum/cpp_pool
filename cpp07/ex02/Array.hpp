/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:25:51 by mababou           #+#    #+#             */
/*   Updated: 2022/03/22 17:58:37 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template< typename T >
class Array {
	
	public:
		Array (void);
		Array (unsigned int n) {
			unsigned int	i;
			
			this->_array = new T(n);
			for (i = 0; i < n; i++) {
				this->_array[i] = 0;
			}
		}



	private:
		T	*_array;

	
};

#endif /* ************************************************************ ITER_H */