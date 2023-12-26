/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:36:10 by sunko             #+#    #+#             */
/*   Updated: 2023/12/26 17:00:04 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
# define HUMAN_B_H

# include <string>
# include <iostream>
# include "Weapon.h"

class HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		HumanB(const std::string &name);
		void				attack(void) const;
		void				setName(const std::string &name);
		const std::string	&getName(void) const;
		void				setWeapon(Weapon &weapon);
		Weapon				*getWeapon(void) const;
};

#endif
