/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 23:35:27 by sunko             #+#    #+#             */
/*   Updated: 2024/01/01 23:52:49 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.h"
# include <string>

class ScavTrap : virtual public ClapTrap
{
	private:
		bool	gateKeeperMode;
		ScavTrap();
	public:
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& source);
		ScavTrap&	operator=(const ScavTrap& source);
		~ScavTrap();
		void		attack(const std::string& target);
		void		guardGate();
		static const int	HIT_POINT;
		static const int	ENERGY_POINT;
		static const int	ATTACK_DAMAGE;
};

#endif
