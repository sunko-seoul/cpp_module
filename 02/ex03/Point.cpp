/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:35:02 by sunko             #+#    #+#             */
/*   Updated: 2023/12/31 16:02:50 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

Point::Point() : x(0), y(0){}

Point::Point(const float fX, const float fY) : x(fX), y(fY){}

Point::Point(const Point& copyPoint) : x(copyPoint.x), y(copyPoint.y){}

Point&	Point::operator=(const Point& copyPoint)
{
	if (this == &copyPoint)
		return (*this);
	const_cast<Fixed&>(this->x) = copyPoint.x;
	const_cast<Fixed&>(this->y) = copyPoint.y;
	return (*this);
}

Point::~Point() {}

Fixed	Point::getX(void) const
{
	return (this->x);
}

Fixed	Point::getY(void) const
{
	return (this->y);
}
