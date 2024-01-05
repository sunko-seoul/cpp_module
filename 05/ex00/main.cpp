/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:20:45 by sunko             #+#    #+#             */
/*   Updated: 2024/01/06 00:05:43 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include <iostream>
#include <string>

int main(void)
{
	try
	{
		Bureaucrat	sunko("sunko", 3);
		Bureaucrat	guma("guma", 150);

		std::cout << sunko << std::endl;
		std::cout << guma << std::endl;
		guma.decreaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "bureaucrat" << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	ggomool("ggomool", 1);
		Bureaucrat	bom("bom", 7);

		std::cout << ggomool << std::endl;
		std::cout << bom << std::endl;
		ggomool.increaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat	sunko("sunko", 200);
		std::cout << sunko << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat	sunko("sunko", 1);
		std::cout << sunko << std::endl;

		Bureaucrat	guma(sunko);
		std::cout << guma << std::endl;

		guma.increaseGrade();
		std::cout << guma << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
