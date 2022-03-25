/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harlhpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:30:10 by mababou           #+#    #+#             */
/*   Updated: 2022/03/15 16:16:14 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HarlHPP
# define HarlHPP

#include <iostream>

class	Harl {
	
	public:

		Harl(void);
		~Harl(void);

		void	complain(std::string level);

	private:

		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);
};

#endif