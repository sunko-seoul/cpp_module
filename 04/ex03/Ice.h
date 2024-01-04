/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:51:52 by sunko             #+#    #+#             */
/*   Updated: 2024/01/04 16:17:08 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

# include "AMateria.h"

class Ice : public AMateria
{
	private:
		Ice();
	public:
		Ice(std::string const & type);
		Ice(const Ice& src);
		~Ice();
		Ice&	operator=(const Ice& src);
		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
