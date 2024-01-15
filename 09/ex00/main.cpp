/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:56:31 by sunko             #+#    #+#             */
/*   Updated: 2024/01/16 00:14:49 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(void)
{
	BitcoinExchange bitcoin("input.txt", "data.csv");

	bitcoin.parseDatabase();
	bitcoin.parseInputData();
}
