/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:09:09 by sunko             #+#    #+#             */
/*   Updated: 2023/10/20 23:23:11 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

Harl::Harl() {};
Harl::~Harl() {};

void	Harl::dubug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
	return ;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*fp[4])(void);
	std::string	level_arr[4];
	int			i;

	fp[0] = &Harl::dubug;
	fp[1] = &Harl::info;
	fp[2] = &Harl::warning;
	fp[3] = &Harl::error;

	level_arr[0] = "DEBUG";
	level_arr[1] = "INFO";
	level_arr[2] = "WARNING";
	level_arr[3] = "ERROR";

	for (i = 0; i < 4; ++i)
	{
		if (level_arr[i] == level)
		{
			(this->*fp[i])();
			return ;
		}
	}

	std::cout << "not define level" << std::endl;
}
