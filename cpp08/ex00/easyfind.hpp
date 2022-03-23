/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:51:28 by mababou           #+#    #+#             */
/*   Updated: 2022/03/23 19:05:51 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <list>
// #include <array>
#include <deque>
#include <stack>
#include <queue>

template <typename T>
int easyfind(T container, int n) {
	
	return (std::find(container.begin(), container.end(), n));
}
