/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:20:45 by sunko             #+#    #+#             */
/*   Updated: 2024/01/06 22:10:31 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Form.h"
#include <iostream>
#include <string>

int main(void)
{
	/* beSigned test */
	try
	{
		Form	form("Confidential documents", 3, 4);
		Bureaucrat	publicOfficial_1("guma", 3);
		Bureaucrat	publicOfficial_2("bom", 4);

		std::cout << "--- form insertion overloading ---" << std::endl;
		std::cout << form;
		std::cout << "----------------------------------" << std::endl;

		form.beSigned(publicOfficial_1);
		form.beSigned(publicOfficial_2);
	}
	catch (const std::exception& e)
	{
		std::cerr << "exception : Bureaucrat" << e.what() << std::endl;
	}
	/* Form grade out bound test*/
	try
	{
		Form	form("Confidential documents", -1, 2);

		Bureaucrat	publicOfficial_1("guma", 3);
		Bureaucrat	publicOfficial_2("bom", 4);

		form.beSigned(publicOfficial_1);
		form.beSigned(publicOfficial_2);

	}
	catch(const std::exception& e)
	{
		std::cerr << "exception : form " << e.what() << std::endl;
	}

	return (0);
}
