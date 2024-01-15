/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:56:31 by sunko             #+#    #+#             */
/*   Updated: 2024/01/16 00:37:43 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: bad argument count" << std::endl;
		std::exit(1);
	}
	BitcoinExchange bitcoin(argv[1], "data.csv");
	bitcoin.parseDatabase();
	bitcoin.parseInputData();
}
