/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:43:36 by sunko             #+#    #+#             */
/*   Updated: 2023/10/18 20:45:09 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie *new_zombie = zombieHorde(5, "sunko_zombie");
	delete []new_zombie;
	return 0;
}
