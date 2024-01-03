/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:50:00 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 12:54:31 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.h"
#include <iostream>

WrongCat::WrongCat()
	: WrongAnimal("WrongCat")
{
	std::cout << "WrongCat defulat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src)
	: WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	mType = src.mType;
}

WrongCat&	WrongCat::operator=(const WrongCat& src)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->mType = src.mType;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat defualt desturctor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Meow~" << std::endl;
}

