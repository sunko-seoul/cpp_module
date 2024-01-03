/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:53:06 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 12:28:11 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"
#include <iostream>

Cat::Cat()
	: Animal("Cat")
{
	std::cout << "Cat defulat constructor called" << std::endl;
}

Cat::Cat(const Cat& src)
	: Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	mType = src.mType;
}

Cat&	Cat::operator=(const Cat& src)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->mType = src.mType;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat defulat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow~" << std::endl;
}
