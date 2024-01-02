/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:08:12 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 00:11:56 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.h"

class Dog : protected Animal
{
	public:
		Dog();
		Dog(const Dog& src);
		Dog&	operator=(const Dog& src);
		virtual	~Dog();
		void	makeSound();
};


#endif
