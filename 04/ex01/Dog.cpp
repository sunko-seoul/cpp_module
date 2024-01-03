/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:39:45 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 15:26:05 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"
#include <iostream>

Dog::Dog()
	: Animal("Dog")
{
	std::cout << "Dog defualt constructor called" << std::endl;
	mBrainP = new Brain;
}

Dog::Dog(const Dog& src)
	: Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	mType = src.mType;
	mBrainP = new Brain(*src.mBrainP);
}

Dog&	Dog::operator=(const Dog& src)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->mType = src.mType;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog defualt copy destructor" << std::endl;
	delete mBrainP;
}

void	Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}


