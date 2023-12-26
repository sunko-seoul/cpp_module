/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:33:37 by sunko             #+#    #+#             */
/*   Updated: 2023/12/26 13:45:12 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>
# include <string>

class Weapon
{
private:
	std::string type;
public:
	Weapon();
	Weapon(const std::string &new_type);
	Weapon& operator=(const Weapon& other);
	~Weapon();
	const std::string& getType(void) const;
	void	setType(const std::string &new_type);
};

#endif
