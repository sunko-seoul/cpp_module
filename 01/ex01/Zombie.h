/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:59:14 by sunko             #+#    #+#             */
/*   Updated: 2023/10/18 20:37:42 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string z_name);
		~Zombie();
		void	announce(void);
		void	set_name(std::string z_name);
};

#endif
