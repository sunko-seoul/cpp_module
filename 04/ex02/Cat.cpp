/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:53:06 by sunko             #+#    #+#             */
/*   Updated: 2024/01/05 02:05:47 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"
#include <iostream>

Cat::Cat()
	: AAnimal("Cat")
{
	std::cout << "Cat defulat constructor called" << std::endl;
	mBrainP = new Brain;
}

Cat::Cat(const Cat& src)
	: AAnimal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	mType = src.mType;
	mBrainP = new Brain(*src.mBrainP);
}

Cat&	Cat::operator=(const Cat& src)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->mType = src.mType;
	*mBrainP = *src.mBrainP;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat defulat destructor called" << std::endl;
	delete mBrainP;
}

void	Cat::makeSound() const
{
	std::cout << "Meow~" << std::endl;
}
