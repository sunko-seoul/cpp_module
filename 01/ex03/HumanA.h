/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:23:23 by sunko             #+#    #+#             */
/*   Updated: 2023/12/26 17:06:23 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
# define HUMAN_A_H

# include <string>
# include <iostream>
# include "Weapon.h"

class HumanA
{
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		HumanA(const std::string &name, Weapon &weapon);
		void				attack(void) const;
		void				setName(const std::string &name);
		const std::string	&getName(void) const;
		void				setWeapon(Weapon &weapon);
		Weapon				*getWeapon(void) const;
};

#endif
