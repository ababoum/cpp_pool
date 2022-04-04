/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_identifiers.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 08:32:35 by mababou           #+#    #+#             */
/*   Updated: 2022/04/04 08:34:27 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_IDENTIFIERS_HPP
# define TYPE_IDENTIFIERS_HPP

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <cstdlib>

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif