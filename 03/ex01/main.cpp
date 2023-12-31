/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:25:25 by sunko             #+#    #+#             */
/*   Updated: 2024/01/01 01:05:18 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"
#include <string>
#include <iostream>

int	main(void)
{
	ScavTrap	player1("sunko");
	ScavTrap	player2("guma");

	player1.attack("guma");
	player2.takeDamage(10);
	player2.beRepaired(5);

	player1.guardGate();
	player1.guardGate();

	return (0);
}
