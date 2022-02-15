/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:07:22 by mababou           #+#    #+#             */
/*   Updated: 2022/02/15 17:38:57 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {

private:
	std::string	_first_name;
	std::string _last_name;
	std::string _nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;
};


#endif