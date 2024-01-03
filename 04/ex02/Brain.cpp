/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:26:37 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 16:05:49 by sunko            ###   ########.fr       */
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
	return (*this);
}

const std::string&	Brain::getIdeas(void) const
{
	return (*ideas);
}

void	Brain::setIdeas(const std::string& src, const int i)
{
	ideas[i] = src;
}
