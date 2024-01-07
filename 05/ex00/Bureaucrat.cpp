/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:40:05 by sunko             #+#    #+#             */
/*   Updated: 2024/01/07 15:48:34 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include <exception>
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat()
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs)
	: mName(rhs.getName()), mGrade(0)
{
	if (rhs.getGrade() < 1)
		throw GradeTooHighException();
	else if (rhs.getGrade() > 150)
		throw GradeTooLowException();
	mGrade = rhs.getGrade();
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this == &rhs)
		return (*this);
	mGrade = rhs.getGrade();
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: mName(name), mGrade(0)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	mGrade = grade;
}

const std::string	Bureaucrat::getName() const
{
	return (mName);
}

int	Bureaucrat::getGrade() const
{
	return (mGrade);
}

void	Bureaucrat::increaseGrade()
{
	if (mGrade > 1)
		mGrade -= 1;
	else if (mGrade == 1)
		throw GradeTooHighException();
}

void	Bureaucrat::decreaseGrade()
{
	if (mGrade < 150)
		mGrade += 1;
	else if (mGrade == 150)
		throw GradeTooLowException();
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is too height!");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low!");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (os);
}

// <name>, bureaucrat grade <grade>.


