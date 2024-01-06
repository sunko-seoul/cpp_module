/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 01:10:44 by sunko             #+#    #+#             */
/*   Updated: 2024/01/07 01:15:05 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_H
# define SHRUBBERY_CREATION_FORM_H

# include "AForm.h"
# include "Bureaucrat.h"
# include <string>
# include <iostream>
# include <exception>

class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string mTarget;
		ShrubberyCreationForm();
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& rhs);
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
		~ShrubberyCreationForm();
		void	execute(Bureaucrat const & executor) const;
		void	createAsciiTree() const;
};

#endif
