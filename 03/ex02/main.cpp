/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:03:10 by sunko             #+#    #+#             */
/*   Updated: 2024/01/01 14:18:33 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"
#include <string>
#include <iostream>

int	main(void)
{
	FragTrap	player1("sunko");
	FragTrap	player2("guma");

	player1.attack("guma");
	player2.takeDamage(10);
	player2.beRepaired(5);

	FragTrap	player3 = player1;
	player1 = player2;

	player1.attack("sunko");
	player3.takeDamage(10);
	player3.beRepaired(5);

	player2.highFivesGuys();
	return (0);
}
