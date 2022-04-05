/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:38:45 by mababou           #+#    #+#             */
/*   Updated: 2022/04/05 18:00:58 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <vector>
# include <stack>

template < typename T >
class MutantStack: public std::stack<T>
{
	public:

		MutantStack<T>() {}
		MutantStack<T>( MutantStack const & src ) {*this = src;}
		~MutantStack<T>();

		MutantStack<T> &		operator=( MutantStack const & rhs )
		{
			if ( this != &rhs )
				this->_stack = rhs._stack;
			return *this;
		};

		bool	empty(void) const;
		size_t	size(void) const;
		T	&	top(void) {
			return (_stack.back());
		};
		void	push(const T & value) {
			_stack.push_back(value);
		};
		void	pop(void);
		
		typename std::vector<T>::iterator	begin(void) {
			return (_stack.begin());
		};
		typename std::vector<T>::iterator	end(void) {
			return (_stack.end());
		}
		
		typedef typename std::vector<T>::iterator iterator;

	private:
		std::vector<T>	_stack;
};


#endif /* ***************************************************** MUTANTSTACK_H */