/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:21:08 by mababou           #+#    #+#             */
/*   Updated: 2022/04/04 08:22:28 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

typedef unsigned long uintptr_t;

struct Data
{
	int			int_vat;
	float		float_val;
	double		double_val;
	std::string	str_val;
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
	Data	*transformed;

	test->int_vat = 159;
	test->float_val = 2.05f;
	test->double_val = 42.42;
	test->str_val = "salut";
	std::cout << test->int_vat << std::endl;
	std::cout << test->float_val << std::endl;
	std::cout << test->double_val << std::endl;
	std::cout << test->str_val << std::endl;

	transformed = deserialize(serialize(test));
	std::cout << transformed << std::endl;
	std::cout << "=============================================" << std::endl;
	std::cout << test << std::endl;

	transformed->int_vat = 247;
	transformed->float_val = 5.02f;
	transformed->double_val = 47.47;
	transformed->str_val = "bye";
	std::cout << transformed->int_vat << std::endl;
	std::cout << transformed->float_val << std::endl;
	std::cout << transformed->double_val << std::endl;
	std::cout << transformed->str_val << std::endl;

	delete test;
	
	return (0);
}
