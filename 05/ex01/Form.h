/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 01:17:28 by sunko             #+#    #+#             */
/*   Updated: 2024/01/06 21:39:17 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include "Bureaucrat.h"
# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string	mFormName;
		bool				mSign;
		const int			mRequiredSignGrade;
		const int			mRequiredExecuteGrade;
		Form();
		Form&	operator=(const Form& rhs);
	public:
		Form(const std::string& formName, const int signGrade, const int executeGrade);
		Form(const Form& rhs);
		~Form();
		const std::string	getFormName() const;
		bool				getSigned() const;
		int					getRequiredSignGrade() const;
		int					getRequiredExecuteGrade() const;
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
		void				beSigned(const Bureaucrat& rhs);
};

std::ostream&	operator<<(std::ostream& os, const Form& rhs);

#endif
