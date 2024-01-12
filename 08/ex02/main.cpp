/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:48:16 by sunko             #+#    #+#             */
/*   Updated: 2024/01/12 16:02:49 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.h"
#include <iostream>

int main()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	//std::cout << mstack.top() << std::endl;

	//mstack.pop();

	//std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(100);
	mstack.push(737);

	//std::cout << mstack.top() << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	// std::cout << *it << std::endl;
	// std::cout << *(++it) << std::endl;
	// std::cout << *(it++) << std::endl;
	// std::cout << *it << std::endl;
	// std::cout << *(--ite) << std::endl;


	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int>	s(mstack);
	return (0);
}
