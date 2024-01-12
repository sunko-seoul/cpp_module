/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:37:06 by sunko             #+#    #+#             */
/*   Updated: 2024/01/12 10:47:34 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <exception>
#include "easyfind.h"

int main(void)
{
	/* vector test */
	try
	{
		std::vector<int>	v;

		for (std::vector<int>::size_type i = 0; i < 10; ++i)
			v.push_back(i);
		std::vector<int>::iterator iter = easyfind(v, 4);
		std::cout << "find " << *iter << " !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::vector<int>	v;

		for (std::vector<int>::size_type i = 0; i < 10; ++i)
			v.push_back(i);
		std::vector<int>::iterator iter = easyfind(v, 200);
		std::cout << "find " << *iter << " !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/* deque test */
	try
	{
		std::deque<int>	v;

		for (std::deque<int>::size_type i = 0; i < 10; ++i)
			v.push_back(i);
		std::deque<int>::iterator iter = easyfind(v, 2);
		std::cout << "find " << *iter << " !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::deque<int>	v;

		for (std::deque<int>::size_type i = 0; i < 10; ++i)
			v.push_back(i);
		std::deque<int>::iterator iter = easyfind(v, 100);
		std::cout << "find " << *iter << " !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/* list */
	try
	{
		std::list<int>	v;

		for (std::list<int>::size_type i = 0; i < 10; ++i)
			v.push_back(i);
		std::list<int>::iterator iter = easyfind(v, 8);
		std::cout << "find " << *iter << " !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::list<int>	v;

		for (std::list<int>::size_type i = 0; i < 10; ++i)
			v.push_back(i);
		std::list<int>::iterator iter = easyfind(v, 50);
		std::cout << "find " << *iter << " !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return (0);
}
