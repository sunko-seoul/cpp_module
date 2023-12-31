/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:30:51 by sunko             #+#    #+#             */
/*   Updated: 2023/12/31 15:56:59 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include <iostream>
# include "Fixed.h"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point();
		Point(const float fX, const float fY);
		Point(const Point& copyPoint);
		Point&	operator=(const Point& copyPoint);
		~Point();
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

#endif
