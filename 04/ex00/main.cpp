/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:03:34 by sunko             #+#    #+#             */
/*   Updated: 2024/01/03 12:57:44 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

int	main()
{
	const	Animal* meta = new Animal();
	const	Animal* j = new Dog();
	const	Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	meta->makeSound();
	i->makeSound();
	j->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;

	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* upcast_wrong_cat = new WrongCat();
	const WrongCat* wrong_cat = new WrongCat();

	std::cout << wrong_meta->getType() << std::endl;
	std::cout << upcast_wrong_cat->getType() << std::endl;

	wrong_meta->makeSound();
	upcast_wrong_cat->makeSound();
	wrong_cat->makeSound();

	delete wrong_meta;
	delete upcast_wrong_cat;
	delete wrong_cat;

	return (0);
}
