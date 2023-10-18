/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:03:56 by sunko             #+#    #+#             */
/*   Updated: 2023/10/18 20:41:45 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>
#include <string>

Zombie::Zombie(std::string z_name)
{
	Zombie::name = z_name;
}

Zombie::~Zombie()
{
	std::cout << Zombie::name << " : " << "I'II Be Back" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << Zombie::name << " : " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
