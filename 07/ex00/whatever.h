/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:58:54 by sunko             #+#    #+#             */
/*   Updated: 2024/01/10 23:04:13 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

template <typename T>
void	swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T	min(T a, T b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>
T	max(T a, T b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif
