/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:46:51 by sunko             #+#    #+#             */
/*   Updated: 2024/01/04 23:26:41 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"
#include "Character.h"
#include "Cure.h"
#include "Ice.h"
#include "ICharacter.h"
#include "IMateriaSource.h"
#include "MateriaSource.h"
#include "SmartPointer.h"

int main(void)
{
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*	me = new Character("me");

	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	// me->unequip(0);
	// me->unequip(1);

	ICharacter*	bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return (0);
}
