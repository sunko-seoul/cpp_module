/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:08:18 by sunko             #+#    #+#             */
/*   Updated: 2024/01/10 23:20:40 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

# include <iostream>

template <typename T, typename F>
void	iter(T *arr, size_t len, F func)
{
	for (size_t i = 0; i < len; ++i)
		func(arr[i]);
}

#endif
