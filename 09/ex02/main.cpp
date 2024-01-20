/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:46:57 by sunko             #+#    #+#             */
/*   Updated: 2024/01/21 00:42:08 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <exception>

std::vector<int>	checkMinusInterger(int argc, char *argv[])
{
	std::vector<int>	v;
	int	i = 1;
	while (i < argc)
	{
		std::stringstream s(argv[i]);
		int a;
		s >> a;
		if (a <= 0)
			throw std::runtime_error("Error");
		int value = a;
		v.push_back(value);
		i++;
	}
	return (v);
}

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cerr << "Error" << std::endl;
		std::exit(1);
	}

	try
	{
		std::vector<int> v = checkMinusInterger(argc, argv);
		std::deque<int> deque;
		for (size_t i = 0; i < v.size(); ++i)
			deque.push_back(v[i]);
		PmergeMe m(v, deque);
		v = m.mergeInsertionSort(v, v.size());
		for (size_t i = 0; i < v.size(); ++i)
			std::cout << v[i] << " ";
		std::cout << std::endl;
		deque = m.mergeInsertionSort(deque, deque.size());
		for (size_t i = 0; i < deque.size(); ++i)
			std::cout << deque[i] << " ";
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
