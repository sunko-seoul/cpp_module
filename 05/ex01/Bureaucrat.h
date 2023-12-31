/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:10:19 by sunko             #+#    #+#             */
/*   Updated: 2024/01/07 15:48:34 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <exception>
# include "Form.h"
class Form;

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
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		void	signForm(const Form& rhs) const;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif
