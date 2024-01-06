/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 00:53:46 by sunko             #+#    #+#             */
/*   Updated: 2024/01/07 01:09:07 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.h"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45),
	  mTarget(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
	: AForm("RobotomyRequestForm", 72, 45),
	  mTarget(rhs.mTarget)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this == &rhs)
		return (*this);
	mTarget = rhs.mTarget;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw AForm::EmptySignException();
	if (executor.getGrade() > this->getRequiredExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	this->infoRobotomizedSuccess();
}

void	RobotomyRequestForm::infoRobotomizedSuccess() const
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::cout << "drilling noises : whirr, whirr, whirr" << std::endl;
	int randomValue = std::rand() % 2;
	std::cout << "info : Robotomized ";
	if (randomValue == 0)
		std::cout << "successfully.";
	else
		std::cout << "failed.";
	std::cout << std::endl;
}





