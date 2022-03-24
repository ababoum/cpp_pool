/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:05:39 by mababou           #+#    #+#             */
/*   Updated: 2022/03/24 19:21:19 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>
# include <iomanip>

class PhoneBook {
	
public:
	
	PhoneBook(void);
	~PhoneBook(void);

	void	add(void);
	void	search(void) const;

private:
	int		_cursor;
	int 	_size;
	Contact	_contact_list[8];

	void	_display(int index, Contact item) const;
	void	_display_all(int index, Contact item) const;
};


#endif