/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:53:43 by sunko             #+#    #+#             */
/*   Updated: 2024/01/04 16:36:59 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.h"
#include <iostream>

Ice::Ice()
{}

Ice::Ice(std::string const & type)
	: AMateria(type)
{
	if (type != "ice")
		mType = "ice";
}

Ice::Ice(const Ice& src)
	: AMateria(src.mType)
{
	if (src.mType != "ice")
		mType = "ice";
}

Ice&	Ice::operator=(const Ice& src)
{
	if (this == &src)
		return (*this);
	if (src.mType == "ice")
		mType = src.mType;
	else
		mType = "ice";
}

Ice::~Ice()
{}

AMateria*	Ice::clone() const
{
	AMateria*	newIce = new Ice("ice");
	return (newIce);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
