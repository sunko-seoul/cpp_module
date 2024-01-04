/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:43:06 by sunko             #+#    #+#             */
/*   Updated: 2024/01/04 22:02:00 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_H
# define MATERIA_SOURCE_H

# include "IMateriaSource.h"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*mSourceSlot[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource& src);
		MateriaSource&	operator=(const MateriaSource& src);
		void		learnMateria(AMateria* materia);
		AMateria*	createMateria(std::string const &type);
};

#endif
