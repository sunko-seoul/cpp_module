/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:22:40 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 15:43:50 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.h"
#include "Cat.h"
#include "Dog.h"

int	main(void)
{
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
	const int		size = 100;
	const Animal*	animalArr[size];

	for (int i = 0; i < 100; ++i)
	{
		if (i % 2 == 0)
			animalArr[i] = new Dog();
		else
			animalArr[i] = new Cat();
	}

	for (int i = 0; i < 100; ++i)
	{
		animalArr[i]->makeSound();
	}

	for (int i = 0; i < 100; ++i)
	{
		delete animalArr[i];
	}

	delete j;
	delete i;
	return (0);
}
