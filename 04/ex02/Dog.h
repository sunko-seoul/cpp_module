/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:08:12 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 16:06:28 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "AAnimal.h"
# include "Animal.h"
# include "Brain.h"

class Dog : public AAnimal
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
