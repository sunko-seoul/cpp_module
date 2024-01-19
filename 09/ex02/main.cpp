/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:46:57 by sunko             #+#    #+#             */
/*   Updated: 2024/01/19 16:02:46 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <exception>

std::vector<std::pair<size_t, size_t> >	checkMinusInterger(int argc, char *argv[])
{
	std::vector<std::pair<size_t, size_t> >	v;
	int	i = 1;
	while (i < argc)
	{
		std::stringstream s(argv[i]);
		int a;
		s >> a;
		if (a <= 0)
			throw std::runtime_error("Error");
		size_t value = a;
		v.push_back(std::make_pair(value, i));
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
		std::vector<std::pair<size_t, size_t> > v = checkMinusInterger(argc, argv);
		std::list<std::pair<size_t, size_t> > list;
		for (size_t i = 0; i < v.size(); ++i)
			list.push_back(v[i]);
		PmergeMe m(v, list);
		v = m.mergeInsertionSort(v, v.size());
		for (size_t i = 0; i < v.size(); ++i)
			std::cout << v[i].first << " ";
		std::cout << std::endl;
		list = m.mergeInsertionSort(list, list.size());
		std::list<std::pair<size_t, size_t> >::iterator lstIter = list.begin();
		for (; lstIter != list.end(); lstIter++)
			std::cout << (*lstIter).first << " ";
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
