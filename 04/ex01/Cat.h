/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:04:18 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 15:15:48 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.h"
# include "Brain.h"

class Cat : public Animal
{
	private:
		Brain	*mBrainP;
	public:
		Cat();
		Cat(const Cat& src);
		Cat&	operator=(const Cat& src);
		~Cat();
		void	makeSound() const;
};

#endif
