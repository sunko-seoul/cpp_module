/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:10:08 by sunko             #+#    #+#             */
/*   Updated: 2024/01/07 15:53:19 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.h"
#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include "Intern.h"
#include <iostream>

int main(void)
{
	/* execute test */
	{
		Bureaucrat	master("master", 1);
		Bureaucrat	publicOfficial1("sunko", 137);
		Bureaucrat	publicOfficial2("guma", 45);
		Bureaucrat	publicOfficial3("bom", 5);
		Intern		intern;

		// ShrubberyCreationForm
		try
		{
			AForm*	SCForm = intern.makeForm("ShrubberyCreationForm", "sunkoHome");
			master.signForm(*SCForm);
			publicOfficial1.executeForm(*SCForm);
			delete SCForm;
			std::cout << std::endl;


			// RobotomyRequestForm
			AForm*	RRForm = intern.makeForm("RobotomyRequestForm", "Bender");
			master.signForm(*RRForm);
			publicOfficial2.executeForm(*RRForm);
			delete RRForm;
			std::cout << std::endl;

			// PresidentialPardonForm
			AForm*	PPForm = intern.makeForm("PresidentialPardonForm", "PresidentBom");
			master.signForm(*PPForm);
			publicOfficial3.executeForm(*PPForm);
			delete PPForm;
			std::cout << std::endl;

			AForm*	WrongForm = intern.makeForm("WrongForm", "42");
			master.signForm(*WrongForm);
			publicOfficial3.executeForm(*WrongForm);
			delete WrongForm;
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

	}
	return (0);
}
