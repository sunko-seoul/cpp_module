/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 23:51:23 by sunko             #+#    #+#             */
/*   Updated: 2024/01/01 14:15:59 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"
#include <iostream>

ScavTrap::ScavTrap(const std::string &name)
	: ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	gateKeeperMode = false;
}

ScavTrap::ScavTrap(const ScavTrap& source)
	: ClapTrap(source)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->setHitPoints(source.getHitPoints());
	this->setEnergyPoints(source.getEnergyPoints());
	this->setAttackDamage(source.getAttackDamage());
	gateKeeperMode = false;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& source)
{
	if (this == &source)
		return (*this);
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	this->setName(source.getName());
	this->setHitPoints(source.getHitPoints());
	this->setEnergyPoints(source.getEnergyPoints());
	this->setAttackDamage(source.getAttackDamage());
	gateKeeperMode = false;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() == 0 || this->getHitPoints() <= 0)
	{
		std::cout << "out of points, can't do anything" << std::endl;
		return ;
	}

	this->setEnergyPoints(this->getEnergyPoints() - 1);
	std::cout << "ScavTrap " << this->getName()
	<< " attack " << target << ", causing " << this->getAttackDamage()
	<< " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (gateKeeperMode)
	{
		std::cout << "ScavTrap " << this->getName() << " gate keeper mode off!" << std::endl;
		gateKeeperMode = false;
	}
	else
	{
		std::cout << "ScavTrap " << this->getName() <<" gate keeper mode on!" << std::endl;
		gateKeeperMode = true;
	}
}


