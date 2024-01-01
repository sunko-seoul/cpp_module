/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:14:04 by sunko             #+#    #+#             */
/*   Updated: 2024/01/01 23:25:19 by sunko            ###   ########.fr       */
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
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& source);
		ClapTrap&	operator=(const ClapTrap& source);
		~ClapTrap();
		void				attack(const std::string& target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
		const std::string	getName(void) const;
		int					getHitPoints(void) const;
		int					getEnergyPoints(void) const;
		int					getAttackDamage(void) const;
		void				setName(const std::string& name);
		void				setHitPoints(const int hitPoints);
		void				setEnergyPoints(const int energyPoints);
		void				setAttackDamage(const int attackDamage);
		static const int	HIT_POINT;
		static const int	ENERGY_POINT;
		static const int	ATTACK_DAMAGE;
};

#endif
