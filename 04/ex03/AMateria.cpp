/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:25:06 by sunko             #+#    #+#             */
/*   Updated: 2024/01/04 12:36:24 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

AMateria::AMateria(std::string const & type)
	: mType(type)
{}

AMateria::AMateria(const AMateria& src)
	: mType(src.mType)
{}

AMateria::~AMateria()
{}

AMateria&	AMateria::operator=(const AMateria& src)
{
	if (this == &src)
		return (*this);
	this->mType = src.mType;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->mType);
}
