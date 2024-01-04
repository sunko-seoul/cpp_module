/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:43:33 by sunko             #+#    #+#             */
/*   Updated: 2024/01/04 16:17:04 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

# include "AMateria.h"

class Cure : public AMateria
{
	private:
		Cure();
	public:
		Cure(std::string const & type);
		Cure(const Cure& src);
		~Cure();
		Cure&	operator=(const Cure& src);
		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
