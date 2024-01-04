/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:24:47 by sunko             #+#    #+#             */
/*   Updated: 2024/01/04 23:09:42 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.h"
# include "AMateria.h"

class AMateria;
class ICharacter;

class Character : public ICharacter
{
	private:
		std::string	mName;
		AMateria	*mSlot[4];
		Character();
	public:
		Character(const std::string& name);
		Character(const Character& src);
		Character&	operator=(const Character& src);
		~Character();
		std::string const & getName() const;
		void	equip(AMateria *m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
		AMateria *getMateria(int idx) const;
};

#endif
