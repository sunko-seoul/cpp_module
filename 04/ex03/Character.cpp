/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:33:16 by sunko             #+#    #+#             */
/*   Updated: 2024/01/05 02:14:21 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.h"
#include "SmartPointer.h"

Character::Character()
{}

Character::Character(const std::string& name)
	: mName(name), mSlot()
{}

Character::Character(const Character& src)
	: mName(src.mName), mSlot()
{
	for (int i = 0; i < 4; ++i)
	{
		if (src.mSlot[i])
			mSlot[i] = src.mSlot[i]->clone();
	}
}

Character&	Character::operator=(const Character& src)
{
	if (this == &src)
		return (*this);
	mName = src.mName;
	for (int i = 0; i < 4; ++i)
	{
		if (mSlot[i])
			delete mSlot[i];
		if (src.mSlot[i])
		mSlot[i] = src.mSlot[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		if (mSlot[i])
			delete mSlot[i];
		mSlot[i] = 0;
	}
}

std::string const & Character::getName() const
{
	return (mName);
}

void	Character::equip(AMateria *m)
{
	int i = 0;
	for (; i < 4; ++i)
	{
		if (mSlot[i] == 0)
			break;
	}

	if (i == 4)
		return ;

	mSlot[i] = m;
}

void	Character::unequip(int idx)
{
	if (mSlot[idx])
	{
		SmartPointer(this->getMateria(idx));
		mSlot[idx] = 0;
	}
	else
		return ;
}

void	Character::use(int idx, ICharacter& target)
{
	if (mSlot[idx])
		mSlot[idx]->use(target);
}

AMateria *Character::getMateria(int idx) const
{
	return (mSlot[idx]);
}
