/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:05:39 by mababou           #+#    #+#             */
/*   Updated: 2022/02/14 18:18:35 by mababou          ###   ########.fr       */
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

	void	ADD(void);
	void	SEARCH(void);
	void	EXIT(void);

private:
	int	cursor;
};


#endif