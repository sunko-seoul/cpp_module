/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:43:57 by sunko             #+#    #+#             */
/*   Updated: 2024/01/07 16:01:27 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

const std::string Intern::formArr[3] = {
	"ShrubberyCreationForm",
	"RobotomyRequestForm",
	"PresidentialPardonForm"
};

Intern::Intern()
{}

Intern::~Intern()
{}

Intern&	Intern::operator=(const Intern& rhs)
{
	if (this == &rhs)
		return (*this);
	return (*this);
}

Intern::Intern(const Intern& rhs)
{
	for (int i = 0; i < 3; ++i)
		const_cast<std::string&>(formArr[i]) = rhs.formArr[i];
}


AForm*	Intern::makeForm(const std::string& formName, const std::string& target)
{
	int i = 0;
	AForm*	concreteFormPtr;
	for (; i < 3; ++i)
	{
		if (formName == formArr[i])
			break ;
	}
	switch (i)
	{
	case 0:
		concreteFormPtr = new ShrubberyCreationForm(target);
		break;
	case 1:
		concreteFormPtr = new RobotomyRequestForm(target);
		break;
	case 2:
		concreteFormPtr = new PresidentialPardonForm(target);
		break;
	default:
		throw Intern::NoMatchFormNameException();
		return (0);
	}
	std::cout << "Intern creates " << formName << std::endl;
	return (concreteFormPtr);
}

const char * Intern::NoMatchFormNameException::what() const throw()
{
	return ("No matching form was found.");
}


