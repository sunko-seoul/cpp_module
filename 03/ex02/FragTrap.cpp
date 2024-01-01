/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 13:42:55 by sunko             #+#    #+#             */
/*   Updated: 2024/01/01 23:52:45 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"
#include <iostream>
#include <string>

const int	FragTrap::HIT_POINT = 100;
const int	FragTrap::ENERGY_POINT = 100;
const int	FragTrap::ATTACK_DAMAGE = 30;

FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap& source)
	: ClapTrap(source)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	this->setHitPoints(source.getHitPoints());
	this->setEnergyPoints(source.getEnergyPoints());
	this->setAttackDamage(source.getAttackDamage());
}

FragTrap&	FragTrap::operator=(const FragTrap& source)
{
	if (this == &source)
		return (*this);
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	this->setName(source.getName());
	this->setHitPoints(source.getHitPoints());
	this->setEnergyPoints(source.getEnergyPoints());
	this->setAttackDamage(source.getAttackDamage());
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Let's high-five guys!" << std::endl;
}

