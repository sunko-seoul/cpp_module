/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:07:08 by sunko             #+#    #+#             */
/*   Updated: 2023/10/19 14:18:10 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str("HI THIS IS BRAIN");
	std::string stringPTR = str; // pointer to the string.
	std::string &stringREF = str; // reference to the string.

	std::cout << &str << std::endl; // the memory address fo the string variable.
	std::cout << &stringPTR << std::endl; // the memory address held by stringPTR.
	std::cout << &stringREF << std::endl; // the memory address held by stringREF.

	std::cout << str << std::endl; // The value of the string variable.
	std::cout << stringPTR << std::endl; // The value pointed to by stringPTR.
	std::cout << stringREF << std::endl; // The value pointed to by stringREF.

	return 0;
}
