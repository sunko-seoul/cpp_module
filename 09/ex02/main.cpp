/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:46:57 by sunko             #+#    #+#             */
/*   Updated: 2024/01/21 15:23:32 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <exception>
#include <ctime>

std::vector<int>	checkMinusInterger(int argc, char *argv[])
{
	std::vector<int>	v;
	int	i = 1;
	while (i < argc)
	{
		std::stringstream s(argv[i]);
		long long a;
		s >> a;
		if (a <= 0 || a > std::numeric_limits<int>::max())
			throw std::runtime_error("Error");
		int value = a;
		v.push_back(value);
		i++;
	}
	return (v);
}

void	printVector(const std::vector<int>& v)
{
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc == 1 || argc > 3001)
	{
		std::cerr << "Error" << std::endl;
		std::exit(1);
	}
	try
	{
		std::vector<int> v = checkMinusInterger(argc, argv);
		std::deque<int> deque;
		PmergeMe m(v, deque);
		std::cout << "Before: ";
		printVector(v);
		m.sortVector();
		m.sortDeque();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
