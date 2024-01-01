/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:33:50 by sunko             #+#    #+#             */
/*   Updated: 2024/01/01 23:51:28 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include <iostream>

const int	ClapTrap::HIT_POINT = 10;
const int	ClapTrap::ENERGY_POINT = 10;
const int	ClapTrap::ATTACK_DAMAGE = 0;

ClapTrap::ClapTrap(const std::string& name)
	: mName(name),
	  mHitPoints(10),
	  mEnergyPoints(10),
	  mAttackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& source)
	: mName(source.getName()),
	  mHitPoints(source.getHitPoints()),
	  mEnergyPoints(source.getEnergyPoints()),
	  mAttackDamage(source.getAttackDamage())
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& source)
{
	if (this == &source)
		return (*this);
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	mName = source.getName();
	mHitPoints = source.getHitPoints();
	mEnergyPoints = source.getEnergyPoints();
	mAttackDamage = source.getAttackDamage();
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() == 0 || this->getHitPoints() <= 0)
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
	if (this->getEnergyPoints() == 0 || this->getHitPoints() <= 0)
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
	if (this->getEnergyPoints() == 0 || this->getHitPoints() <= 0)
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

int	ClapTrap::getEnergyPoints(void) const
{
	return (mEnergyPoints);
}

int	ClapTrap::getAttackDamage(void) const
{
	return (mAttackDamage);
}

void	ClapTrap::setName(const std::string& name)
{
	this->mName = name;
}

void	ClapTrap::setHitPoints(const int hitPoints)
{
	this->mHitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(const int energyPoints)
{
	this->mEnergyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(const int attackDamage)
{
	this->mAttackDamage = attackDamage;
}
