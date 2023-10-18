/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:03:56 by sunko             #+#    #+#             */
/*   Updated: 2023/10/18 20:45:27 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>
#include <string>

Zombie::Zombie(){};

Zombie::Zombie(std::string z_name)
{
	Zombie::name = z_name;
}

Zombie::~Zombie()
{
	std::cout << name << " : " << "I'II Be Back" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << " : " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string z_name)
{
	Zombie::name = z_name;
}
