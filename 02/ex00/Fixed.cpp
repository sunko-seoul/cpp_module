/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:33:27 by sunko             #+#    #+#             */
/*   Updated: 2023/12/31 18:58:21 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>

Fixed::Fixed()
	: mRawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copyFixed)
{
	std::cout << "Copy constructor called" << std::endl;
	mRawBits = copyFixed.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& copyFixed)
{
	if (this == &copyFixed)
		return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(copyFixed.getRawBits());
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->mRawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->mRawBits = raw;
}
