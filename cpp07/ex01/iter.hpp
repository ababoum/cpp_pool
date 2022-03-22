/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:25:51 by mababou           #+#    #+#             */
/*   Updated: 2022/03/22 17:41:46 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template< typename T >
void	iter(T * lst, size_t size, void (*funct)(T)) {
	size_t	i;

	for (i = 0; i < size; i++) {
		funct(lst[i]);
	}
};


#endif /* ************************************************************ ITER_H */