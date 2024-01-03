/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:38:32 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 12:47:15 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.h"

WrongAnimal::WrongAnimal()
	: mType("Animal")
{
	std::cout << "WrongAnimal defulat constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	mType = src.mType;
}

WrongAnimal::WrongAnimal(const std::string& type)
	: mType(type)
{
	std::cout << "WrongAnimal constructor with arguments called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& src)
{
	std::cout << "WrongAnimal copy operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->mType = src.mType;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal defulat destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal!" << std::endl;
}

const std::string& WrongAnimal::getType(void) const
{
	return (this->mType);
}
