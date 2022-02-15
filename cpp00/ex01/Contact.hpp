/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:07:22 by mababou           #+#    #+#             */
/*   Updated: 2022/02/15 12:46:13 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {

public:
	std::string	first_name;
	std::string last_name;
	std::string nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};


#endif