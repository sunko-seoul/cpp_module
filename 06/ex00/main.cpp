/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:16:46 by sunko             #+#    #+#             */
/*   Updated: 2024/01/09 10:18:22 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
		std::exit(1);

	ScalarConverter::convert(static_cast<std::string>(argv[1]));
	return (0);
}
