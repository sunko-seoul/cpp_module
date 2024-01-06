/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 00:22:10 by sunko             #+#    #+#             */
/*   Updated: 2024/01/07 00:42:40 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5),
	  mTarget(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs)
	: AForm("PresidentialPardonForm", 25, 5),
	  mTarget(rhs.mTarget)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this == &rhs)
		return (*this);
	mTarget = rhs.mTarget;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw EmptySignException();
	if (executor.getGrade() > this->getRequiredExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	this->infoPardon();
}


void	PresidentialPardonForm::infoPardon() const
{
	std::cout << "info : " << mTarget << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
