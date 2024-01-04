/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:33:16 by sunko             #+#    #+#             */
/*   Updated: 2024/01/04 17:09:11 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.h"

Character::Character()
{}

Character::Character(const std::string& name)
	: mName(name)
{
	for (int i = 0; i < 4; ++i)
		mSlot[i] = 0;
}

Character::Character(const Character& src)
	: mName(src.mName)
{
	for (int i = 0; i < 4; ++i)
	{
		if (mSlot[i])
			delete mSlot[i];
		mSlot[i] = 0;
		mSlot[i] = src.mSlot[i];
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
		mSlot[i] = 0;
		mSlot[i] = src.mSlot[i];
	}
}

Character::~Character()
{}

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

}

void	Character::use(int idx, ICharacter& target)
{
	if (mSlot[idx])
		mSlot[idx]->use(target);
}
