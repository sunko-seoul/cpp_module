/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 00:10:14 by sunko             #+#    #+#             */
/*   Updated: 2024/01/07 00:49:25 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_H
# define PRESIDENTIAL_PARDON_FORM_H

# include "AForm.h"
# include "Bureaucrat.h"
# include <string>
# include <iostream>
# include <exception>

class AForm;

class PresidentialPardonForm : public AForm
{
	private:
		std::string	mTarget;
		PresidentialPardonForm();
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& rhs);
	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& rhs);
		~PresidentialPardonForm();
		void	execute(Bureaucrat const & executor) const;
		void	infoPardon() const;
};

#endif
