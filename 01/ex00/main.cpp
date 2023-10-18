/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:10:35 by sunko             #+#    #+#             */
/*   Updated: 2023/10/18 17:13:39 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

int	main(void)
{
	Zombie* new_zombie = newZombie("sunko");
	new_zombie->announce();
	delete new_zombie;

	randomChump("goma");
	return 0;
}
