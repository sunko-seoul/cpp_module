/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 00:43:53 by sunko             #+#    #+#             */
/*   Updated: 2024/01/07 00:53:40 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTO_MY_REQUEST_FORM_H
# define ROBOTO_MY_REQUEST_FORM_H

# include "AForm.h"
# include "Bureaucrat.h"
# include <string>
# include <iostream>
# include <exception>

class AForm;

class RobotomyRequestForm : public AForm
{
	private:
		std::string mTarget;
		RobotomyRequestForm();
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& rhs);
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& rhs);
		~RobotomyRequestForm();
		void	execute(Bureaucrat const & executor) const;
		void	infoRobotomizedSuccess() const;
};

#endif
