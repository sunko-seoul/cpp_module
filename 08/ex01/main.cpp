/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:55:36 by sunko             #+#    #+#             */
/*   Updated: 2024/01/12 12:06:45 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

unsigned int	getRandomUnsignedInt(void)
{
	return (static_cast<unsigned int>(rand()));
}

int main(void)
{
	const int numberCount = 10005;
	std::srand(static_cast<unsigned int>(std::time(0)));

	{
		Span randomVector(numberCount);
		for (int i = 0; i < numberCount; ++i)
			randomVector.addNumber(getRandomUnsignedInt());

		unsigned int shortestDistance = randomVector.shortestSpan();
		unsigned int longestDistance = randomVector.longestSpan();

		std::cout << "shortest distance : " << shortestDistance << std::endl;
		std::cout << "longest distance : " << longestDistance << std::endl;
	}

	{
		Span vec(numberCount);

		for (int i =0; i < numberCount; ++i)
			vec.addNumber(i);

		unsigned int shortestDistance = vec.shortestSpan();
		unsigned int longestDistance = vec.longestSpan();

		std::cout << "shortest distance : " << shortestDistance << std::endl;
		std::cout << "longest distance : " << longestDistance << std::endl;
	}

	return (0);
}
