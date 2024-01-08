/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:03:43 by sunko             #+#    #+#             */
/*   Updated: 2024/01/08 11:19:17 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"

Serializer::Serializer()
	: mData(0)
{}

Serializer::Serializer(const Serializer& rhs)
	: mData(rhs.mData)
{}

Serializer&	Serializer::operator=(const Serializer& rhs)
{
	if (this == &rhs)
		return (*this);
	this->mData = rhs.mData;
	return (*this);
}

Serializer::~Serializer()
{}

uintptr_t	Serializer::serializer(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserializer(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
