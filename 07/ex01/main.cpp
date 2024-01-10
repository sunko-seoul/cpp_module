/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:20:42 by sunko             #+#    #+#             */
/*   Updated: 2024/01/10 23:25:51 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.h"

void	printInt(int element)
{
	std::cout << element << " ";
}

void	printString(const std::string& s)
{
	std::cout << s << " ";
}

int	main(void)
{
	int	intArray[] = {1, 2, 3, 4, 5};
	size_t	arrayLength = sizeof(intArray) / sizeof(int);

	std::cout << "Int: ";
	iter(intArray, arrayLength, printInt);
	std::cout << std::endl;

	std::string	strArray[] = {"42", "seoul", "sunko"};
	arrayLength = sizeof(strArray) / sizeof(std::string);

	std::cout << "String: ";
	iter(strArray, arrayLength, printString);
	std::cout << std::endl;
}
