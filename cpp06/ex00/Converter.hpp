/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:11:40 by mababou           #+#    #+#             */
/*   Updated: 2022/03/18 16:58:16 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>

class Converter
{

	public:

		Converter();
		Converter(std::string input);
		Converter( Converter const & src );
		~Converter();

		Converter &		operator=( Converter const & rhs );

		std::string			toChar(void);
		std::string			toInt(void);
		std::string			toFloat(void);
		std::string			toDouble(void);
		

		std::string		getInput(void) const;

	private:
		std::string		_input;

};

std::ostream &			operator<<( std::ostream & o, Converter const & i );

#endif /* ******************************************************* CONVERTER_H */