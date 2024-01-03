/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:04:18 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 16:06:25 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "AAnimal.h"
# include "Animal.h"
# include "Brain.h"


class Cat : public AAnimal
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
