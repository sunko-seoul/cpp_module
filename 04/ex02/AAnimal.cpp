/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:56:33 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 16:05:14 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.h"

AAnimal::AAnimal()
	: mType("AAnimal")
{
	std::cout << "AAnimal defulat constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	mType = src.mType;
}

AAnimal::AAnimal(const std::string& type)
	: mType(type)
{
	std::cout << "AAnimal constructor with arguments called" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& src)
{
	std::cout << "AAnimal copy operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->mType = src.mType;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal defualt destructor called" << std::endl;
}

const std::string& AAnimal::getType(void) const
{
	return (this->mType);
}
