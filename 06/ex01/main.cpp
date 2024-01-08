/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:11:49 by sunko             #+#    #+#             */
/*   Updated: 2024/01/08 11:16:17 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"
#include <iostream>

int main()
{
	Data	d1;
	d1.data = 0;

	std::cout << &d1 << std::endl;
	uintptr_t	p1 = Serializer::serializer(&d1);
	std::cout << p1 << std::endl;
	Data	*dp = Serializer::deserializer(p1);
	std::cout << dp << std::endl;
}
