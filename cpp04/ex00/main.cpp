/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:57:16 by mababou           #+#    #+#             */
/*   Updated: 2022/02/23 16:31:58 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"
# include "Dog.hpp"

int main()
{
	const Animal*	meta = new Animal();
	const Animal*	i = new Cat();
	Animal*			i2 = new Cat();
	Animal*			i3 = new Cat();
	const Animal*	j = new Dog();
	
	i2->setType("Tom");
	*i3 = *i2;
	
	std::cout << i3->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	i3->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete i2;
	delete i3;
	delete j;
	
	return (0);
}