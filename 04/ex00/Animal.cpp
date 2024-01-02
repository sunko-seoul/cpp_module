/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:12:59 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 00:29:06 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.h"

Animal::Animal()
	: mType(0)
{
	std::cout << "Animal defulat constructor called" << std::endl;
}

Animal::Animal(const std::string& type)
	: mType(type)
{
	std::cout << "Animal passed string constructor called" << std::endl;
}

Animal::Animal(const Animal& src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	mType = src.mType;
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

void	makeSound()
{
	std::cout << "Animal!" << std::endl;
}
