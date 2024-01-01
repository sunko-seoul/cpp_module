/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:00:27 by sunko             #+#    #+#             */
/*   Updated: 2024/01/01 23:16:42 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include <string>
# include "ScavTrap.h"
# include "FragTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string mName;
		DiamondTrap();
	public:
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& source);
		DiamondTrap&	operator=(const DiamondTrap& sourec);
		~DiamondTrap();
		void	whoAmI();
};

#endif
