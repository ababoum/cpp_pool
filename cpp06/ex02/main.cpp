/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:59:01 by mababou           #+#    #+#             */
/*   Updated: 2022/04/04 10:29:10 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "type_identifiers.hpp"

int main(void)
{
	srand(time(NULL));
	
	Base	*t1, *t2, *t3;

	t1 = generate();
	t2 = generate();
	t3 = generate();

	identify(t1);
	identify(t2);
	identify(t3);

	std::cout << "====================================" << std::endl;

	A	a;
	B	b;
	C	c;

	identify(a);
	identify(b);
	identify(c);
	
	delete t1;
	delete t2;
	delete t3;
	
	return (0);
}