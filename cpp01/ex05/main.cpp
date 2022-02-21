/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:04:42 by mababou           #+#    #+#             */
/*   Updated: 2022/02/21 14:22:25 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(void)
{
	Karen	chipie;

	chipie.complain("DEBUG");
	chipie.complain("INFO");
	chipie.complain("WARNING");
	chipie.complain("ERROR");
	
	return (0);
}