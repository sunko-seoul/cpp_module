/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:39:45 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 12:28:33 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"
#include <iostream>

Dog::Dog()
	: Animal("Dog")
{
	std::cout << "Dog defualt constructor called" << std::endl;
}

Dog::Dog(const Dog& src)
	: Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->mType = src.mType;
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
}

void	Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}


