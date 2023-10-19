/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:33:37 by sunko             #+#    #+#             */
/*   Updated: 2023/10/19 14:43:56 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string type;
public:
	Weapon();
	Weapon(const std::string& new_type);
	~Weapon();
	const std::string& getType(void);
	void	setType(const std::string &new_type);
};


