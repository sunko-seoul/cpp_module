/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:04:18 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 00:11:18 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.h"

class Cat : protected Animal
{
	public:
		Cat();
		Cat(const Cat& src);
		Cat&	operator=(const Cat& src);
		virtual	~Cat();
		void	makeSound();
};

#endif
