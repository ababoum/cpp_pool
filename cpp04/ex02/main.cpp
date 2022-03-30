/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:57:16 by mababou           #+#    #+#             */
/*   Updated: 2022/03/30 15:08:00 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"
# include "Dog.hpp"

int main()
{
	Animal	*zoo[10];
	int 	i;

	for (i = 0; i < 5; i++) {
		zoo[i] = new Cat();
	}
	for (i = 5; i < 10; i++) {
		zoo[i] = new Dog();
	}
	
	for (i = 0; i < 10; i++) {
		zoo[i]->makeSound();
	}

	for (i = 0; i < 10; i++) {
		delete zoo[i];
	}


	std::cout << "==============================================" << std::endl;

	Dog	milou;
	// Animal	meta; // this won't compile because Animal is abstract
	
	milou.getBrain()->getIdeas()[0] = "waf";
	milou.getBrain()->getIdeas()[1] = "nonosss";
	milou.getBrain()->getIdeas()[2] = "steak";

	Dog tintin(milou);

	milou.getBrain()->getIdeas()[0] = "salut";
	milou.getBrain()->getIdeas()[1] = "bonjour";
	milou.getBrain()->getIdeas()[2] = "bye";

	std::cout << tintin.getBrain()->getIdeas()[0] << std::endl;
	std::cout << tintin.getBrain()->getIdeas()[1] << std::endl;
	std::cout << tintin.getBrain()->getIdeas()[2] << std::endl;

	std::cout << milou.getBrain()->getIdeas()[0] << std::endl;
	std::cout << milou.getBrain()->getIdeas()[1] << std::endl;
	std::cout << milou.getBrain()->getIdeas()[2] << std::endl;

	std::cout << "==============================================" << std::endl;

	Dog	milou2;
	
	milou2.getBrain()->getIdeas()[0] = "waf";
	milou2.getBrain()->getIdeas()[1] = "nonosss";
	milou2.getBrain()->getIdeas()[2] = "steak";

	Dog tintin2 = milou2;

	milou2.getBrain()->getIdeas()[0] = "salut";
	milou2.getBrain()->getIdeas()[1] = "bonjour";
	milou2.getBrain()->getIdeas()[2] = "bye";

	std::cout << tintin2.getBrain()->getIdeas()[0] << std::endl;
	std::cout << tintin2.getBrain()->getIdeas()[1] << std::endl;
	std::cout << tintin2.getBrain()->getIdeas()[2] << std::endl;

	std::cout << milou2.getBrain()->getIdeas()[0] << std::endl;
	std::cout << milou2.getBrain()->getIdeas()[1] << std::endl;
	std::cout << milou2.getBrain()->getIdeas()[2] << std::endl;

	
	std::cout << "==============================================" << std::endl;

	const Animal* j = new Dog();
	const Animal* c = new Cat();
	
	delete j;
	delete c;

	std::cout << "==============================================" << std::endl;

	
	return (0);
}