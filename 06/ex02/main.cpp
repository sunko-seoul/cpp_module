/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:07:06 by sunko             #+#    #+#             */
/*   Updated: 2024/01/08 16:30:25 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

Base	*generate(void)
{
	std::srand(std::time(0));
	int randomNumber = rand() % 3;
	Base*	BasePtr;

	switch (randomNumber)
	{
		case 0:
			BasePtr = new A;
			break;
		case 1:
			BasePtr = new B;
			break;
		case 2:
			BasePtr = new C;
			break;
	}
	return (BasePtr);
}

void	identify(Base* p)
{
	A	*aPtr;
	B	*bPtr;
	C	*cPtr;

	aPtr = dynamic_cast<A*>(p);
	if (aPtr)
	{
		std::cout << "A" << std::endl;
		return ;
	}
	bPtr = dynamic_cast<B*>(p);
	if (bPtr)
	{
		std::cout << "B" << std::endl;
		return ;
	}
	cPtr = dynamic_cast<C*>(p);
	if (cPtr)
	{
		std::cout << "C" << std::endl;
		return ;
	}
}

void	identify(Base& p)
{
	try
	{
		A	aRef = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}

	try
	{
		B	bRef = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	try
	{
		C	cRef = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
}

int main(void)
{
	Base	*p = generate();

	identify(p);
	identify(*p);

	delete p;
	return (0);
}
