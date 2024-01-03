/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:08:12 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 15:21:19 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.h"
# include "Brain.h"

class Dog : public Animal
{
	private:
		Brain	*mBrainP;
	public:
		Dog();
		Dog(const Dog& src);
		Dog&	operator=(const Dog& src);
		~Dog();
		void	makeSound() const;
};


#endif
