/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:43:41 by mababou           #+#    #+#             */
/*   Updated: 2022/03/30 20:27:30 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// std::cout << src->getMateriaList()[0]->getType() << std::endl;
	// std::cout << src->getMateriaList()[1]->getType() << std::endl;
	
	ICharacter* me = new Character("me");

	AMateria* tmp1;
	AMateria* tmp2;
	
	tmp1 = src->createMateria("ice");
	me->equip(tmp1);
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);

	// std::cout << me->getInventory()[0]->getType() << std::endl;
	// std::cout << me->getInventory()[1]->getType() << std::endl;
	
	ICharacter* bob = new Character("bob");
	
	std::cout << me->getName() << ": ";
	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(1);
	delete tmp2;

	std::cout << "==============================================" << std::endl;

	Character	robert("robert");
	AMateria* 	tmp3;

	tmp3 = src->createMateria("cure");
	robert.equip(tmp3);

	std::cout << robert.getName() << ": ";
	robert.use(0, *bob);

	Character	michel(robert);
	
	robert.unequip(0);
	delete tmp3;

	std::cout << michel.getName() << ": ";
	michel.use(0, *bob);

	std::cout << robert.getName() << ": ";
	robert.use(0, *bob);

	delete bob;
	delete me;
	delete src;
	
	return (0);
}