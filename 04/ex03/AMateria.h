/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:56:39 by sunko             #+#    #+#             */
/*   Updated: 2024/01/04 16:08:48 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_H
# define A_MATERIA_H

# include <string>
# include "ICharacter.h"

class AMateria
{
	protected:
		std::string	mType;
		AMateria();
	public:
		AMateria(std::string const & type);
		AMateria(const AMateria& src);
		~AMateria();
		AMateria&	operator=(const AMateria& src);
		std::string const &getType() const; // Returns the materia type
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
