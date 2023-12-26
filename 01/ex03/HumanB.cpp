/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:38:34 by sunko             #+#    #+#             */
/*   Updated: 2023/12/26 16:59:44 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"

HumanB::HumanB(const std::string &name)
	: name(name)
{}

void	HumanB::attack(void) const
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setName(const std::string &name)
{
	this->name = name;
}

const std::string	&HumanB::getName(void) const
{
	return (this->name);
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

Weapon	*HumanB::getWeapon(void) const
{
	return (this->weapon);
}
