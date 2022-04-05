/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:12:03 by mababou           #+#    #+#             */
/*   Updated: 2022/04/05 12:14:43 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span(): _size(0)
{
}

Span::Span(unsigned int N): _size(N)
{
}

Span::Span( const Span & src ): _size(src._size)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	std::vector<int>::const_iterator	it;
	
	for (it = rhs._list.begin(); it!= rhs._list.end(); ++it) {
		this->addNumber(*it);
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Span const & i )
{
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Span::addNumber(int nb)
{
	if (_list.size() >= _size)
		throw FullSpanException();
	else
	{
		_list.push_back(nb);
	}
}

long	Span::shortestSpan(void) const
{
	std::vector<int>	tmp = _list;
	long	shortest = std::numeric_limits<long>::max();
	int		int_buffer = 0;

	if (this->_list.size() <= 1)
		throw ShortSpanException();
	else {
		std::sort(tmp.begin(), tmp.end());
		std::vector<int>::iterator	it = tmp.begin();
		
		while (42)
		{
			int_buffer = *it;
			if (++it == tmp.end())
				break ;
			if (static_cast<long>(*it) - static_cast<long>(int_buffer) < shortest)
				shortest = static_cast<long>(*it) - static_cast<long>(int_buffer);
		}
		return (shortest);
	}	
}

long	Span::longestSpan(void) const
{
	return (static_cast<long>(*std::max_element(_list.begin(), _list.end())) - \
			static_cast<long>(*std::min_element(_list.begin(), _list.end())));
}

void	Span::fillSpan(unsigned int N)
{
	for (unsigned int i = 0; i < N; i++) {
		this->addNumber(rand());
	}
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */