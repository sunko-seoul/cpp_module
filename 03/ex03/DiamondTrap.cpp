/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:00:04 by sunko             #+#    #+#             */
/*   Updated: 2024/01/01 23:40:53 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"),
	  ScavTrap(name),
	  FragTrap(name),
	  mName(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->setHitPoints(FragTrap::HIT_POINT);
	this->setEnergyPoints(ScavTrap::ENERGY_POINT);
	this->setAttackDamage(FragTrap::ATTACK_DAMAGE);
}

DiamondTrap::DiamondTrap(const DiamondTrap& source)
	: ClapTrap(source.getName() + "_clap_name"),
	  ScavTrap(source.getName()),
	  FragTrap(source.getName()),
	  mName(source.mName)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->setName(source.getName());
	this->setHitPoints(source.getHitPoints());
	this->setEnergyPoints(source.getEnergyPoints());
	this->setAttackDamage(source.getAttackDamage());
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& source)
{
	if (this == &source)
		return (*this);
	std::cout << "Diamond copy assignment operator called" << std::endl;
	mName = source.mName;
	this->setName(source.getName());
	this->setHitPoints(source.getHitPoints());
	this->setEnergyPoints(source.getEnergyPoints());
	this->setAttackDamage(source.getAttackDamage());
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap: " << mName << std::endl;
	std::cout << "ClapTrap: " << ClapTrap::getName() << std::endl;
}
