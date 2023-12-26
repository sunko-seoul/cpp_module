/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:32:00 by sunko             #+#    #+#             */
/*   Updated: 2023/12/26 21:18:54 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"

HumanA::HumanA(const std::string &name, Weapon &weapon)
	: name(name), weapon(&weapon)
{}

void	HumanA::attack(void) const
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanA::setName(const std::string &name)
{
	this->name = name;
}

const std::string	&HumanA::getName(void) const
{
	return (this->name);
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

Weapon	*HumanA::getWeapon(void) const
{
	return (this->weapon);
}


