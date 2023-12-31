/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:33:50 by sunko             #+#    #+#             */
/*   Updated: 2023/12/31 22:58:26 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include <iostream>

ClapTrap::ClapTrap(std::string& name)
	: mName(name),
	  mHitPoints(10),
	  mEnergyPoints(10),
	  mAttackDamage(0)
{
	std::cout << "constructor given name parameter called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& source)
	: mName(source.getName()),
	  mHitPoints(source.getHitPoints()),
	  mEnergyPoints(source.getEnergyPoint()),
	  mAttackDamage(source.getAttackDamage())
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& source)
{
	if (this == &source)
		return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
	mName = source.getName();
	mHitPoints = source.getHitPoints();
	mEnergyPoints = source.getEnergyPoint();
	mAttackDamage = source.getAttackDamage();
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->getEnergyPoint() == 0 || this->getHitPoints() <= 0)
	{
		std::cout << "out of points, can't do anything" << std::endl;
		return ;
	}

	mEnergyPoints -= 1;
	std::cout << "ClapTrap " << this->getName()
	<< " attack " << target << ", causing " << this->getAttackDamage()
	<< " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getEnergyPoint() == 0 || this->getHitPoints() <= 0)
	{
		std::cout << "out of points, can't do anything" << std::endl;
		return ;
	}

	mHitPoints -= amount;
	std::cout << this->getName() << " take a damage, "
	<< "lose " << amount << " Hit points!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoint() == 0 || this->getHitPoints() <= 0)
	{
		std::cout << "out of points, can't do anything" << std::endl;
		return ;
	}

	mEnergyPoints -= 1;
	mHitPoints += amount;
	std::cout << this->getName() << " be Repaired, "
	<< "gets "<< amount << " hit points!" << std::endl;
}

const std::string	ClapTrap::getName(void) const
{
	return (mName);
}

int	ClapTrap::getHitPoints(void) const
{
	return (mHitPoints);
}

int	ClapTrap::getEnergyPoint(void) const
{
	return (mEnergyPoints);
}

int	ClapTrap::getAttackDamage(void) const
{
	return (mAttackDamage);
}
