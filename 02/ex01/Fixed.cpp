/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:33:27 by sunko             #+#    #+#             */
/*   Updated: 2023/12/30 01:49:11 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>
#include <cmath>

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
	*this = copyFixed;
}

Fixed::Fixed(const int iRawBits)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(iRawBits);
}

Fixed::Fixed(const float fRawBits)
{
	int	mul = 1;

	std::cout << "Float constructor called" << std::endl;
	for (int i = 0; i < this->mNumOfFractionBit; ++i)
		mul *= 10;
	this->setRawBits(static_cast<int>(roundf(fRawBits * mul)));
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

float	Fixed::toFloat(void) const
{
	float		floatingPointNumber;
	int			divide = 1;

	for (int i = 0; i < this->mNumOfFractionBit; ++i)
		divide *= 10;

	floatingPointNumber = static_cast<float>(this->getRawBits()) / divide;
	return (floatingPointNumber);
}

int	Fixed::toInt(void) const
{
	int		integerNumber;
	int		divide = 1;

	for (int i = 0; i < this->mNumOfFractionBit; ++i)
		divide *= 10;

	integerNumber = this->getRawBits() / divide;
	return (integerNumber);
}
