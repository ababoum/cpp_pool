/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongmain.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:57:16 by mababou           #+#    #+#             */
/*   Updated: 2022/03/17 14:28:09 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"

int main()
{
	const WrongAnimal*	meta = new WrongAnimal();
	const WrongAnimal*	i = new WrongCat();
	WrongAnimal*		i2 = new WrongCat();
	WrongAnimal*		i3 = new WrongCat();
	
	*i3 = *i2;
	
	std::cout << i3->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	i3->makeSound(); //will output the cat sound!
	meta->makeSound();

	delete meta;
	delete i;
	delete i2;
	delete i3;
	
	return (0);
}