/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:20:10 by sunko             #+#    #+#             */
/*   Updated: 2024/01/12 10:44:32 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

# include <iostream>
# include <algorithm>
# include <exception>

template <typename T>
typename T::iterator	easyfind(T first, int second)
{
	typename T::iterator iter = std::find(first.begin(), first.end(), second);

	if (iter == first.end())
		throw std::runtime_error("Element not found");
	return (iter);
}

#endif
