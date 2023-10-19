/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:41:41 by sunko             #+#    #+#             */
/*   Updated: 2023/10/19 14:46:19 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon() {}
Weapon::~Weapon() {}

Weapon::Weapon(const std::string& new_type)
{
	Weapon::type = new_type;
}

const std::string& Weapon::getType(void)
{
	return Weapon::type;
}

void	Weapon::setType(const std::string &new_type)
{
	Weapon::type = new_type;
}

