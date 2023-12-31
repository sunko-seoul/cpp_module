/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:33:50 by sunko             #+#    #+#             */
/*   Updated: 2023/12/31 19:03:16 by sunko            ###   ########.fr       */
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

std::string	ClapTrap::getName(void) const
{
	return (mName);
}

int	ClapTrap::getHitPoints(void) const
{
	return (mHitPoints);
}

int	ClapTrap::getEnergyPoint(void) const
{
	return (mEnergyPoints)
}

int	ClapTrap::getAttackDamage(void) const
{
	return (mAttackDamage);
}
