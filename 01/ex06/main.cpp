/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:32:07 by sunko             #+#    #+#             */
/*   Updated: 2023/12/28 00:12:09 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"
#include <locale>

int	main(int argc, char *argv[])
{
	Harl				harl;
	const std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string			argv_str;
	std::string			str;
	int					levelIdx = 0;

	if (argc != 2)
	{
		std::cerr << "Usage : ./harlFilter <argument1> " << std::endl;
		return (1);
	}
	argv_str = argv[1];
	for (std::string::size_type i = 0; i < argv_str.length(); i++)
	{
		if (std::isspace(argv_str[i]))
			continue;
		str += std::toupper(argv_str[i]);
	}

	for (; levelIdx < 4; levelIdx++)
	{
		if (levels[levelIdx] == str)
			break ;
	}

	switch (levelIdx)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
			std::cout << std::endl;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
			std::cout << std::endl;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
			std::cout << std::endl;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
	return (0);
}
