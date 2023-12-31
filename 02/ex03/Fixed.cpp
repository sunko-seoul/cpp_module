/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:33:27 by sunko             #+#    #+#             */
/*   Updated: 2023/12/31 18:59:01 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>
#include <cmath>

Fixed::Fixed()
	: mRawBits(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copyFixed)
{
	std::cout << "Copy constructor called" << std::endl;
	mRawBits = copyFixed.getRawBits();
}

Fixed::Fixed(const int intValue)
{
	//std::cout << "Int constructor called" << std::endl;
	mRawBits = intValue << mNumOfFractionBit;
}

Fixed::Fixed(const float floatValue)
{
	//std::cout << "Float constructor called" << std::endl;
	mRawBits = static_cast<int>(roundf(floatValue * (1 << mNumOfFractionBit)));
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
	//std::cout << "Copy assignment operator called" << std::endl;
	mRawBits = copyFixed.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed& fixed) const
{
	return (mRawBits > fixed.getRawBits());
}

bool	Fixed::operator<(const Fixed& fixed) const
{
	return (mRawBits < fixed.getRawBits());
}

bool	Fixed::operator>=(const Fixed& fixed) const
{
	return (mRawBits >= fixed.getRawBits());
}

bool	Fixed::operator<=(const Fixed& fixed) const
{
	return (mRawBits <= fixed.getRawBits());
}

bool	Fixed::operator==(const Fixed& fixed) const
{
	return (mRawBits == fixed.getRawBits());
}

bool	Fixed::operator!=(const Fixed& fixed) const
{
	return (mRawBits != fixed.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed&	Fixed::operator++(void)
{
	mRawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmpFixed(this->toFloat());

	(this->mRawBits)++;
	return (tmpFixed);
}

Fixed&	Fixed::operator--(void)
{
	mRawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmpFixed(this->toFloat());

	(this->mRawBits)--;
	return (tmpFixed);
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
	return (static_cast<float>(mRawBits) / (1 << mNumOfFractionBit));
}

int	Fixed::toInt(void) const
{
	return (mRawBits >> mNumOfFractionBit);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1.getRawBits() <= f2.getRawBits())
		return (f1);
	else
		return (f2);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() <= f2.getRawBits())
		return (f1);
	else
		return (f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	else
		return (f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	else
		return (f2);
}

