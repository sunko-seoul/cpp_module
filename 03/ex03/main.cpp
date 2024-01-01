/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 22:38:39 by sunko             #+#    #+#             */
/*   Updated: 2024/01/01 23:44:48 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"
#include <string>
#include <iostream>

int	main(void)
{
	DiamondTrap	player1("sunko");
	DiamondTrap	player2(player1);
	DiamondTrap	player3("guma");

	// Frag(30), Scav(50), Frag(100)
	std::cout << "attackDamage(1) : " << player1.getAttackDamage() << std::endl;
	std::cout << "EnergyPoint(1) : " << player1.getEnergyPoints() << std::endl;
	std::cout << "hitPoints(1) : " << player1.getHitPoints() << std::endl;

	std::cout << "attackDamage(2) : " << player2.getAttackDamage() << std::endl;
	std::cout << "EnergyPoint(2) : " << player2.getEnergyPoints() << std::endl;
	std::cout << "hitPoints(2) : " << player2.getHitPoints() << std::endl;

	player1 = player3;
	std::cout << "attackDamage(1) : " << player1.getAttackDamage() << std::endl;
	std::cout << "EnergyPoint(1) : " << player1.getEnergyPoints() << std::endl;
	std::cout << "hitPoints(1) : " << player1.getHitPoints() << std::endl;

	player1.whoAmI();
}
