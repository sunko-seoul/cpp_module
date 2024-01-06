/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 01:26:01 by sunko             #+#    #+#             */
/*   Updated: 2024/01/06 21:44:21 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.h"

Form::Form(const std::string& formName, const int signGrade, const int executeGrade)
	: mFormName(formName),
	  mSign(0),
	  mRequiredSignGrade(signGrade),
	  mRequiredExecuteGrade(executeGrade)
{
	if (mRequiredSignGrade < 1 || mRequiredExecuteGrade < 1)
		throw GradeTooHighException();
	else if (mRequiredSignGrade > 150 || mRequiredExecuteGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& rhs)
	: mFormName(rhs.getFormName()),
	  mSign(0),
	  mRequiredSignGrade(rhs.getRequiredSignGrade()),
	  mRequiredExecuteGrade(rhs.getRequiredExecuteGrade())
{
	if (mRequiredSignGrade < 1 || mRequiredExecuteGrade < 1)
		throw GradeTooHighException();
	else if (mRequiredSignGrade > 150 || mRequiredExecuteGrade > 150)
		throw GradeTooLowException();
}

Form&	Form::operator=(const Form& rhs)
{
	if (this == &rhs)
		return (*this);
	mSign = rhs.mSign;
	return (*this);
}

Form::~Form()
{}

const std::string	Form::getFormName() const
{
	return (mFormName);
}

bool			Form::getSigned() const
{
	return (mSign);
}

int			Form::getRequiredSignGrade() const
{
	return (mRequiredSignGrade);
}

int			Form::getRequiredExecuteGrade() const
{
	return (mRequiredExecuteGrade);
}

const char * Form::GradeTooHighException::what() const _NOEXCEPT
{
	return ("grade is too high!");
}

const char * Form::GradeTooLowException::what() const _NOEXCEPT
{
	return ("grade is too low!");
}

void	Form::beSigned(const Bureaucrat& rhs)
{
	if (mRequiredSignGrade >= rhs.getGrade())
	{
		mSign = 1;
		rhs.signForm(*this);
	}
	else
	{
		mSign = 0;
		rhs.signForm(*this);
		throw	Form::GradeTooLowException();
	}
}

std::ostream&	operator<<(std::ostream& os, const Form& rhs)
{
	os << "FormName : " << rhs.getFormName() << std::endl
	<< "signed(1 or 0) : " << rhs.getSigned() << std::endl
	<< "required to sign it grade : " << rhs.getRequiredSignGrade() << std::endl
	<< "required to execute it grade : " << rhs.getRequiredExecuteGrade() << std::endl;
	return (os);
}

