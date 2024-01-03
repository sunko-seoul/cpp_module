/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:53:40 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 15:56:27 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ANIMAL_H
# define A_ANIMAL_H

# include <string>

class AAnimal
{
	protected:
		std::string	mType;
	public:
		AAnimal();
		AAnimal(const std::string& type);
		AAnimal(const AAnimal& src);
		AAnimal& operator=(const AAnimal& src);
		virtual	~AAnimal();
		virtual void	makeSound() const = 0;
		const std::string&	getType(void) const;
};

#endif
