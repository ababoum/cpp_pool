/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:07:22 by mababou           #+#    #+#             */
/*   Updated: 2022/03/10 16:20:40 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {

	public:

	Contact(void);
	~Contact(void);
	
	void		setFirstName(std::string first_name);
	void		setLastName(std::string last_name);
	void		setNickname(std::string nickname);
	void		setPhoneNumber(std::string phone_number);
	void		setDarkestSecret(std::string darkest_secret);
	std::string	getFirstName(void);
	std::string	getLastName(void);
	std::string	getNickname(void);
	std::string	getPhoneNumber(void);
	std::string	getDarkestSecret(void);
	
	private:

	std::string	_first_name;
	std::string _last_name;
	std::string _nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;
};


#endif