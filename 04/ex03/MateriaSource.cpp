/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:50:33 by sunko             #+#    #+#             */
/*   Updated: 2024/01/05 02:18:40 by sunko            ###   ########.fr       */
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
	: mSourceSlot()
{
	for (int i = 0; i < 4; ++i)
	{
		if (mSourceSlot[i])
			mSourceSlot[i] = mSourceSlot[i]->clone();
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& src)
{
	if (this == &src)
		return (*this);
	for (int i = 0; i < 4; ++i)
	{
		if (mSourceSlot[i])
			delete mSourceSlot[i];
		if (src.mSourceSlot[i])
			mSourceSlot[i] = src.mSourceSlot[i]->clone();
	}
	return (*this);
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
		if (mSourceSlot[i] && mSourceSlot[i]->getType() == type)
			break ;
	}
	if (i == 4)
		return (0);
	return (mSourceSlot[i]->clone());
}

