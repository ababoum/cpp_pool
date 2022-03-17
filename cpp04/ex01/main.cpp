/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:57:16 by mababou           #+#    #+#             */
/*   Updated: 2022/03/17 17:27:00 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"
# include "Dog.hpp"

int main()
{
	Animal	*animals[10];
	
	for (int i = 0; i < 5; i++)
	{
		animals[i] = new Cat();
	}
	for (int i = 5; i < 10; i++)
	{
		animals[i] = new Dog();
	}
	
	animals[0]->makeSound();
	animals[6]->makeSound();

	for (int i = 0; i < 10; i++)
		delete animals[i];

	return (0);		
}