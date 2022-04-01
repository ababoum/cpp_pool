/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:21:08 by mababou           #+#    #+#             */
/*   Updated: 2022/04/01 22:27:20 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

typedef unsigned long uintptr_t;

struct Data
{
	int	value;
};

uintptr_t serialize(Data* ptr)
{
	uintptr_t output;

	output = reinterpret_cast<uintptr_t>(ptr);
	return (output);
}

Data* deserialize(uintptr_t raw)
{
	Data *output;

	output = reinterpret_cast<Data *>(raw);
	return (output);
}

int main(void)
{
	Data	*test = new Data;

	test->value = 159;
	std::cout << test->value << std::endl;

	std::cout << deserialize(serialize(test)) << std::endl;
	std::cout << test << std::endl;

	test->value = 247;
	std::cout << test->value << std::endl;

	delete test;
	
	return (0);
}
