/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:04:21 by sunko             #+#    #+#             */
/*   Updated: 2024/01/06 23:36:17 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_H
# define A_FORM_H

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.h"

class Bureaucrat;

class AForm
{
	private:
		const std::string	mFormName;
		bool				mSign;
		const int			mRequiredSignGrade;
		const int			mRequiredExecuteGrade;
		AForm();
		AForm&	operator=(const AForm& rhs);
	public:
		AForm(const std::string& formName, const int signGrade, const int executeGrade);
		AForm(const AForm& rhs);
		virtual ~AForm();
		const std::string	getFormName() const;
		bool				getSigned() const;
		int					getRequiredSignGrade() const;
		int					getRequiredExecuteGrade() const;
		virtual void		execute(Bureaucrat const & executor) const = 0;
		void				beSigned(const Bureaucrat& rhs);
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const _NOEXCEPT;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const _NOEXCEPT;
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& rhs);

#endif
