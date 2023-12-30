/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:33:27 by sunko             #+#    #+#             */
/*   Updated: 2023/12/30 21:11:36 by sunko            ###   ########.fr       */
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
	this->setRawBits(iRawBits << this->getNumOfFractionBit());
}

Fixed::Fixed(const float fRawBits)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(static_cast<int>(roundf(fRawBits * (1 << this->getNumOfFractionBit()))));
}

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << static_cast<float>(fixed.getRawBits()) / (1 << fixed.getNumOfFractionBit());
	return (out);
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
	return (this->mRawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->mRawBits = raw;
}

int	Fixed::getNumOfFractionBit(void) const
{
	return (this->mNumOfFractionBit);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << this->getNumOfFractionBit()));
}

int	Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->getNumOfFractionBit());
}
