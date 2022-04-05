/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:12:03 by mababou           #+#    #+#             */
/*   Updated: 2022/04/05 16:40:50 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <limits>
# include <cstdlib>

class Span
{
	public:
	
		class FullSpanException: public std::exception
		{
			public:
				virtual const char * what() const throw() {
					return ("\e[41m The span is full; no new number can be added \e[0m");
				}		
		};

		class ShortSpanException: public std::exception
		{
			public:
				virtual const char * what() const throw() {
					return ("\e[41m The span is too short; no distance can be computed \e[0m");
				}		
		};

		Span (unsigned int N);
		Span( Span const & src );
		~Span();

		Span &		operator=( Span const & rhs );

		void	addNumber(int nb);
		long	shortestSpan(void) const;
		long	longestSpan(void) const;
		void	fillSpan(unsigned int N);

		template <typename T>
		void	fillSpan(typename T::iterator beg, typename T::iterator end) {
			typename T::iterator	it = beg;
			
			while (it != end) {
				this->addNumber(*(it++));
			}
		}

	private:
		std::vector<int>	_list;
		const unsigned int	_capacity;
		
		Span();

};

std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */