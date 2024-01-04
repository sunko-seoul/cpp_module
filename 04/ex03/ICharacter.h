/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:11:54 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 21:31:54 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_CHARACTER_H
# define I_CHARACTER_H

# include <string>
# include "AMateria.h"

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void	equip(AMateria* m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter& target) = 0;
};

#endif
