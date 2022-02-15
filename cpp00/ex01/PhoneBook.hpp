/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:05:39 by mababou           #+#    #+#             */
/*   Updated: 2022/02/15 13:16:06 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	
public:
	Contact	contact_list[8];
	
	PhoneBook(void);
	~PhoneBook(void);

	void	add(void);
	void	search(void);

private:
	int	cursor;
	int size;

	void	display(int index, Contact item);
};


#endif