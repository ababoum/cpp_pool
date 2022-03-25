/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:30:10 by mababou           #+#    #+#             */
/*   Updated: 2022/02/22 18:41:10 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Harl_HPP
# define Harl_HPP

#include <iostream>

# define DEBUG_LVL 0
# define INFO_LVL 1
# define WARNING_LVL 2
# define ERROR_LVL 3

class	Harl {
	
public:

	Harl(std::string filter);
	~Harl(void);

	void	complain(std::string level);
	int		convert_filter(std::string level) const;
	int		getFilter(void) const;

private:

	int		_filter;
	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);
	void	_display_filter(int filter) const;
};

#endif