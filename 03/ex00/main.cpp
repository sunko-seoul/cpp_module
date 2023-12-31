/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 22:48:34 by sunko             #+#    #+#             */
/*   Updated: 2024/01/01 01:01:48 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include <string>

int	main(void)
{
	ClapTrap	player1("sunko");
	ClapTrap	player2("guma");

	player1.attack("guma");
	player2.takeDamage(player1.getAttackDamage());
	player2.beRepaired(2);
	return (0);
}
