/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:45:29 by sunko             #+#    #+#             */
/*   Updated: 2024/01/04 16:35:14 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.h"
#include <iostream>

Cure::Cure()
{}

Cure::Cure(std::string const & type)
	: AMateria(type)
{
	if (type != "cure")
		mType = "cure";
}

Cure::Cure(const Cure& src)
	: AMateria(src.mType)
{
	if (src.mType != "cure")
		mType = "cure";
}

Cure&	Cure::operator=(const Cure& src)
{
	if (this == &src)
		return (*this);
	if (src.mType == "cure")
		mType = src.mType;
	else
		mType = "cure";
}

Cure::~Cure()
{}

AMateria*	Cure::clone(void) const
{
	AMateria*	newCure = new Cure("cure");
	return (newCure);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
