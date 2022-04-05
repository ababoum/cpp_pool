/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:38:45 by mababou           #+#    #+#             */
/*   Updated: 2022/04/05 19:33:06 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <deque>
# include <list>
# include <stack>

template < typename T >
class MutantStack: public std::stack<T>
{
	public:

		MutantStack<T>() {}
		MutantStack<T>( MutantStack const & src ) {this->c = src.c;}
		~MutantStack<T>() {}

		MutantStack<T> &		operator=( MutantStack const & rhs )
		{
			this->c = rhs.c;
			return *this;
		};
		
		typedef typename std::deque<T>::iterator iterator;

		bool	empty(void) const { return this->c.empty(); };
		size_t	size(void) const { return this->c.size(); };
		T	&	top(void) {
			return (this->c.back());
		};
		void	push(const T & value) {
			this->c.push_back(value);
		};
		void	pop(void) {this->c.pop_back(); };
		
		iterator	begin(void) {
			return (this->c.begin());
		};
		iterator	end(void) {
			return (this->c.end());
		}

};


#endif /* ***************************************************** MUTANTSTACK_H */