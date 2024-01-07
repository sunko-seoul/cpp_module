/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:39:33 by sunko             #+#    #+#             */
/*   Updated: 2024/01/07 00:38:24 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <exception>
# include "AForm.h"

class AForm;

class Bureaucrat
{
	private:
		const std::string	mName;
		int					mGrade;
		Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat& rhs);
	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& rhs);
		virtual ~Bureaucrat();
		const std::string	getName() const;
		int					getGrade() const;
		void				setGrade(int grade);
		void				increaseGrade();
		void				decreaseGrade();
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
		void	signForm(AForm& form) const;
		void	executeForm(const AForm& form);
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif
