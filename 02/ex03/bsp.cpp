/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:32:35 by sunko             #+#    #+#             */
/*   Updated: 2023/12/31 17:38:44 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"


// 0.5 * (x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2))
static float	getTriangleArea(Point const p1, Point const p2, Point const p3)
{
	float	area;
	Fixed	tempFixed(p1.getX() * (p2.getY() - p3.getY())\
	+ p2.getX() * (p3.getY() - p1.getY())\
	+ p3.getX() * (p1.getY() - p2.getY()));

	area = 0.5 * std::abs(tempFixed.toFloat());
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	triangle1 = getTriangleArea(a, b, point);
	float	triangle2 = getTriangleArea(point, b, c);
	float	triangle3 = getTriangleArea(a, c, point);
	float	originTriangle = getTriangleArea(c, a, b);

	if (originTriangle != 0 && (originTriangle == (triangle1 + triangle2 + triangle3)))
		return (true);
	else
		return (false);
}

