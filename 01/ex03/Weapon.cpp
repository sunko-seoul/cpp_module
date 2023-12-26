/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:41:41 by sunko             #+#    #+#             */
/*   Updated: 2023/12/26 16:25:37 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon() {}
Weapon::~Weapon() {}

Weapon::Weapon(const std::string& new_type)
{
	Weapon::type = new_type;
}

Weapon& Weapon::operator=(const Weapon& other)
{
	if (this != &other)
	{
		this->type = other.getType();
	}
	return *this;
}

const std::string& Weapon::getType(void) const
{
	return Weapon::type;
}

void	Weapon::setType(const std::string &new_type)
{
	this->type = new_type;
}

