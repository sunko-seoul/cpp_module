/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:14:04 by sunko             #+#    #+#             */
/*   Updated: 2023/12/31 18:59:46 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

struct ClapTrap
{
	private:
		std::string	mName;
		int			mHitPoints;
		int			mEnergyPoints;
		int			mAttackDamage;
		ClapTrap();
	public:
		ClapTrap(std::string& name);
		ClapTrap(const ClapTrap& source);
		ClapTrap&	operator=(const ClapTrap& source);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoint(void) const;
		int			getAttackDamage(void) const;
};

#endif
