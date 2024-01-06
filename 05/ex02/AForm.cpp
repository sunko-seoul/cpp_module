/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:16:01 by sunko             #+#    #+#             */
/*   Updated: 2024/01/07 00:27:34 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.h"

AForm::AForm(const std::string& formName, const int signGrade, const int executeGrade)
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

AForm::AForm(const AForm& rhs)
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

AForm&	AForm::operator=(const AForm& rhs)
{
	if (this == &rhs)
		return (*this);
	mSign = rhs.mSign;
	return (*this);
}

AForm::~AForm()
{}

const std::string	AForm::getFormName() const { return (mFormName); }
bool				AForm::getSigned() const { return (mSign); }
int					AForm::getRequiredSignGrade() const { return (mRequiredSignGrade); }
int					AForm::getRequiredExecuteGrade() const { return (mRequiredExecuteGrade); }


void	AForm::beSigned(const Bureaucrat& rhs)
{
	if (mRequiredExecuteGrade >= rhs.getGrade())
		mSign = 1;
	else
	{
		mSign = 0;
		throw	Bureaucrat::GradeTooLowException();
	}
}

const char * AForm::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Form grade is too high!");
}

const char * AForm::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Form grade is too low!");
}


std::ostream&	operator<<(std::ostream& os, const AForm& rhs)
{
	os << "FormName : " << rhs.getFormName() << std::endl
	<< "signed(1 or 0) : " << rhs.getSigned() << std::endl
	<< "required to sign it grade : " << rhs.getRequiredSignGrade() << std::endl
	<< "required to execute it grade : " << rhs.getRequiredExecuteGrade() << std::endl;
	return (os);
}
