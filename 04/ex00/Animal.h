/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:47:29 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 00:29:26 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <string>

class Animal
{
	protected:
		std::string	mType;
	public:
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& src);
		Animal&	operator=(const Animal& src);
		virtual	~Animal();
		virtual void	makeSound();
};

#endif
