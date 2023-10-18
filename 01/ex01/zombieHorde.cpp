/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:32:37 by sunko             #+#    #+#             */
/*   Updated: 2023/10/18 20:45:20 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*new_zombie = new Zombie[N];

	for (int i = 0; i < N; ++i)
	{
		new_zombie[i].set_name(name);
		new_zombie[i].announce();
	}
	return new_zombie;
}
