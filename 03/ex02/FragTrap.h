/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 13:37:53 by sunko             #+#    #+#             */
/*   Updated: 2024/01/01 23:52:28 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.h"
# include <string>

struct FragTrap : virtual public ClapTrap
{
	private:
		FragTrap();
	public:
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& source);
		FragTrap&	operator=(const FragTrap& source);
		~FragTrap();
		void	highFivesGuys(void);
		static const int	HIT_POINT;
		static const int	ENERGY_POINT;
		static const int	ATTACK_DAMAGE;
};

#endif
