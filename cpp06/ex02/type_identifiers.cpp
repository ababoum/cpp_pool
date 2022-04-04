/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_identifiers.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 08:26:06 by mababou           #+#    #+#             */
/*   Updated: 2022/04/04 10:29:06 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "type_identifiers.hpp"

Base	*generate(void)
{
	int 	roulette;

	roulette = rand() % 3;
	
	switch (roulette)
	{
	case 0:
		return (new A);
		break;
	
	case 1:
		return (new B);
		break;

	case 2:
		return (new C);
		break;
	
	default:
		return (0);
		break;
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type identified: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type identified: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type identified: C" << std::endl;
	else
		std::cout << "Type identified: Unknown" << std::endl;
}

void	identify(Base& p)
{
	Base	*test = 0;
	
	try
	{
		*test = dynamic_cast<A&>(p);
	}
	catch (std::exception e)
	{
		try
		{
			*test = dynamic_cast<B&>(p);
		}
		catch (std::exception e)
		{
			try
			{
				*test = dynamic_cast<C&>(p);
			}
			catch (std::exception e)
			{
				std::cout << "Type identified: Unknown" << std::endl;
				return ;
			}
			std::cout << "Type identified: C" << std::endl;
			return ;
		}
		std::cout << "Type identified: B" << std::endl;
		return ;
	}
	std::cout << "Type identified: A" << std::endl;
	return ;
}
