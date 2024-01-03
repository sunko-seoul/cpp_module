/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:26:37 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 14:35:18 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.h"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain defualt constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain defualt destructor called" << std::endl;
}

Brain::Brain(const Brain& src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
		ideas[i] = src.ideas[i];
}

Brain&	Brain::operator=(const Brain& src)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	for (int i = 0; i < 100; ++i)
		ideas[i] = src.ideas[i];
}
