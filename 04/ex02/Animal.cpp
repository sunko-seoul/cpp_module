/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:12:59 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 12:27:59 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.h"

Animal::Animal()
	: mType("Animal")
{
	std::cout << "Animal defulat constructor called" << std::endl;
}

Animal::Animal(const Animal& src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	mType = src.mType;
}

Animal::Animal(const std::string& type)
	: mType(type)
{
	std::cout << "Animal constructor with arguments called" << std::endl;
}

Animal&	Animal::operator=(const Animal& src)
{
	std::cout << "Animal copy operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->mType = src.mType;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal defulat destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal!" << std::endl;
}

const std::string& Animal::getType(void) const
{
	return (this->mType);
}
