/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:50:33 by sunko             #+#    #+#             */
/*   Updated: 2024/01/04 22:11:22 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.h"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		mSourceSlot[i] = 0;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (mSourceSlot[i])
		{
			delete mSourceSlot[i];
			mSourceSlot[i] = 0;
		}
	}
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	for (int i = 0; i < 4; ++i)
	{
		if (mSourceSlot[i])
		{
			delete mSourceSlot[i];
			mSourceSlot[i] = 0;
		}
		mSourceSlot[i] = src.mSourceSlot[i];
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& src)
{
	if (this == &src)
		return (*this);
	for (int i = 0; i < 4; ++i)
	{
		if (mSourceSlot[i])
		{
			delete mSourceSlot[i];
			mSourceSlot[i] = 0;
		}
		mSourceSlot[i] = src.mSourceSlot[i];
	}
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	int i = 0;
	for (; i < 4; ++i)
	{
		if (mSourceSlot[i] == 0)
			break ;
	}
	if (i == 4)
		return ;
	mSourceSlot[i] = materia;
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	int i = 0;
	for (; i < 4; ++i)
	{
		if (mSourceSlot[i]->getType() == type)
			break ;
	}
	if (i == 4)
		return (0);
	return (mSourceSlot[i]->clone());
}

