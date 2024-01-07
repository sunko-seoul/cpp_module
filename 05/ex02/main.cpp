/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:10:08 by sunko             #+#    #+#             */
/*   Updated: 2024/01/07 13:32:33 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.h"
#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include <iostream>

int main(void)
{
	/* execute test (no sign exception) */
	{
		Bureaucrat	publicOfficial1("sunko", 137);
		Bureaucrat	publicOfficial2("guma", 45);
		Bureaucrat	publicOfficial3("bom", 5);

		// ShrubberyCreationForm
		AForm*	SCForm = new ShrubberyCreationForm("sunkoHome");
		publicOfficial1.executeForm(*SCForm);

		// RobotomyRequestForm
		AForm*	RRForm = new RobotomyRequestForm("guma robote");
		publicOfficial2.executeForm(*RRForm);

		// PresidentialPardonForm
		AForm*	PPForm = new PresidentialPardonForm("president bom");
		publicOfficial3.executeForm(*PPForm);


		delete SCForm;
		delete RRForm;
		delete PPForm;
		std::cout << std::endl;
	}

	/* execute test (low execute level exception) */
	{
		Bureaucrat	master("master", 1);
		Bureaucrat	publicOfficial1("sunko", 138);
		Bureaucrat	publicOfficial2("guma", 46);
		Bureaucrat	publicOfficial3("bom", 6);

		// ShrubberyCreationForm
		AForm*	SCForm = new ShrubberyCreationForm("sunkoHome");
		master.signForm(*SCForm);
		publicOfficial1.executeForm(*SCForm);


		// RobotomyRequestForm
		AForm*	RRForm = new RobotomyRequestForm("guma robote");
		master.signForm(*RRForm);
		publicOfficial2.executeForm(*RRForm);

		// PresidentialPardonForm
		AForm*	PPForm = new PresidentialPardonForm("president bom");
		master.signForm(*PPForm);
		publicOfficial3.executeForm(*PPForm);


		delete SCForm;
		delete RRForm;
		delete PPForm;
		std::cout << std::endl;
	}

	/* execute test */
	{
		Bureaucrat	master("master", 1);
		Bureaucrat	publicOfficial1("sunko", 137);
		Bureaucrat	publicOfficial2("guma", 45);
		Bureaucrat	publicOfficial3("bom", 5);

		// ShrubberyCreationForm
		AForm*	SCForm = new ShrubberyCreationForm("sunkoHome");
		master.signForm(*SCForm);
		publicOfficial1.executeForm(*SCForm);


		// RobotomyRequestForm
		AForm*	RRForm = new RobotomyRequestForm("guma robote");
		master.signForm(*RRForm);
		publicOfficial2.executeForm(*RRForm);

		// PresidentialPardonForm
		AForm*	PPForm = new PresidentialPardonForm("president bom");
		master.signForm(*PPForm);
		publicOfficial3.executeForm(*PPForm);


		delete SCForm;
		delete RRForm;
		delete PPForm;
		std::cout << std::endl;
	}
	return (0);
}
