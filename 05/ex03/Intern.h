/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:20:36 by sunko             #+#    #+#             */
/*   Updated: 2024/01/07 15:48:13 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include <string>
# include "AForm.h"
# include <exception>

class AForm;

class Intern
{
	private:
		static const std::string formArr[3];
		Intern(const Intern& rhs);
		Intern&	operator=(const Intern& rhs);
	public:
		Intern();
		~Intern();
		AForm*	makeForm(const std::string& formName, const std::string& target);
		class NoMatchFormNameException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
