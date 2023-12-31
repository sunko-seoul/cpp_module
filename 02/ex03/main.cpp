/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:53:08 by sunko             #+#    #+#             */
/*   Updated: 2023/12/31 17:39:33 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include "Point.h"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	a(0.0, 0.0);
	Point	b(1.0, 0.0);
	Point	c(0.5, 0.5);

	Point	p1(0.0, 0.0);
	Point	p2(6.0, 1.0);

	if (bsp(a, b, c, p1))
		std::cout << "in" << std::endl;
	else
		std::cout << "out" << std::endl;

	if (bsp(a, b, c, p2))
		std::cout << "in" << std::endl;
	else
		std::cout << "out" << std::endl;

	return (0);
}
