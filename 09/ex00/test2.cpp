/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:04:57 by sunko             #+#    #+#             */
/*   Updated: 2024/01/15 22:29:11 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include <locale>
#include <iomanip> // get_time

int	dateStringToNumber(const std::string& dateStr)
{
	std::tm tm = {};
	std::istringstream iss(dateStr);
	iss >> std::get_time(&tm, "%Y-%m-%d");

	std::cout << tm.tm_year + 1900 << std::endl;
	std::cout << tm.tm_mon + 1 << std::endl;
	std::cout << tm.tm_mday << std::endl;
	std::time_t	timestamp = std::mktime(&tm);

	std::cout << "time : " << timestamp << std::endl;
	return (timestamp);
}


int main(void)
{
	std::string dateStr1 = "2011-01-03";
	std::string dateStr2 = "2011-01-05";

	int dateNum1 = dateStringToNumber(dateStr1);
	int dateNum2 = dateStringToNumber(dateStr2);

	if (dateNum1 > dateNum2)
		std::cout << "1" << std::endl;
	else
		std::cout << "2" << std::endl;
}
