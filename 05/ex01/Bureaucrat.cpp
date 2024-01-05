/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:40:05 by sunko             #+#    #+#             */
/*   Updated: 2024/01/06 02:19:00 by sunko            ###   ########.fr       */
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
	: mName(rhs.getName()), mGrade(rhs.getGrade())
{
	if (mGrade < 1)
		throw GradeTooHighException();
	else if (mGrade > 150)
		throw GradeTooLowException();
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this == &rhs)
		return (*this);
	mGrade = rhs.getGrade();
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: mName(name), mGrade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

const std::string	Bureaucrat::getName() const
{
	return (mName);
}

int	Bureaucrat::getGrade() const
{
	return (mGrade);
}

void	Bureaucrat::setGrade(int grade)
{
	mGrade = grade;
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

const char * Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return ("grade is too height!");
}

const char * Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return ("grade is too low!");
}

void	Bureaucrat::signForm(const Form& rhs) const
{
	if (rhs.getSigned())
		std::cout << this->getName() << " signed " << rhs.getFormName() << std::endl;
	else
		std::cout << this->getName() << " couldn't sign " << rhs.getFormName() << " because " << this->getName() << "'s grade is too low" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (os);
}

// <name>, bureaucrat grade <grade>.


