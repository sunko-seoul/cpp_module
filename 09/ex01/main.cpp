/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:49:30 by sunko             #+#    #+#             */
/*   Updated: 2024/01/15 00:02:06 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <exception>
#include "RPN.hpp"

int main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
			throw std::invalid_argument("Error : invalid argument count");
		std::string	argvString(argv[1]);
		if (std::find(argvString.begin(), argvString.end(), '(') != argvString.end() \
		|| std::find(argvString.begin(), argvString.end(), ')') != argvString.end())
			throw std::invalid_argument("Error : invalid brackets");
		for (std::string::size_type i = 0; i < argvString.size(); ++i)
		{
			if (std::isalpha(argvString[i]))
				throw std::invalid_argument("Error : invalid alphabet");
			if (i < argvString.size() - 1 && std::isdigit(argvString[i]) && std::isdigit(argvString[i + 1]))
				throw std::invalid_argument("Error : invalid digit");
		}
		RPN	rpn(argvString);
		rpn.calculateExpr();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
