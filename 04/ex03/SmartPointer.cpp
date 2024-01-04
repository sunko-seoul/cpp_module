/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SmartPointer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:19:14 by sunko             #+#    #+#             */
/*   Updated: 2024/01/04 23:18:27 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SmartPointer.h"

SmartPointer::SmartPointer()
	: mMateriaPtr(0)
{}

SmartPointer&	SmartPointer::operator=(const SmartPointer& src)
{
	if (this == &src)
		return (*this);
	if (mMateriaPtr)
		delete mMateriaPtr;
	this->mMateriaPtr = src.mMateriaPtr;
	return *this;
}

SmartPointer::SmartPointer(const SmartPointer& src)
	: mMateriaPtr(src.mMateriaPtr)
{}

SmartPointer::SmartPointer(AMateria* materiaPtr)
	: mMateriaPtr(materiaPtr)
{}

SmartPointer::~SmartPointer()
{
	delete mMateriaPtr;
}
