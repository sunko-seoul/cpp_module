/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:03:56 by sunko             #+#    #+#             */
/*   Updated: 2023/10/18 17:07:40 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>
#include <string>

Zombie::Zombie(std::string z_name)
{
	name = z_name;
}

Zombie::~Zombie()
{
	std::cout << name << " : " << "I'II Be Back" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << " : " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
