/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:04:18 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 12:48:26 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.h"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& src);
		Cat&	operator=(const Cat& src);
		~Cat();
		void	makeSound() const;
};

#endif
