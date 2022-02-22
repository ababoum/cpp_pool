/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:30:10 by mababou           #+#    #+#             */
/*   Updated: 2022/02/22 18:41:10 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# define DEBUG_LVL 0
# define INFO_LVL 1
# define WARNING_LVL 2
# define ERROR_LVL 3

#include <iostream>

class	Karen {
	
public:

	Karen(void);
	~Karen(void);

	void	complain(std::string level, int filter) const;
	void	display_filter(int filter) const;
	int		convert_filter(std::string level) const;

private:

	void	_debug(void) const;
	void	_info(void) const;
	void	_warning(void) const;
	void	_error(void) const;
};

#endif