/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:08:31 by sunko             #+#    #+#             */
/*   Updated: 2024/01/12 12:04:55 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"
#include <exception>
#include <algorithm>

Span::Span()
	: N(0)
{}

Span::Span(unsigned int n)
	: N(n)
{
	mVec.reserve(0);
}

Span::Span(const Span& rhs)
	: N(rhs.N)
{
	for (std::vector<unsigned int>::size_type i = 0; i < rhs.mVec.size(); ++i)
		mVec.push_back(rhs.mVec[i]);
}

Span&	Span::operator=(const Span& rhs)
{
	if (this == &rhs)
		return (*this);
	N = rhs.N;
	mVec = rhs.mVec;
	return (*this);
}

Span::~Span()
{}

void	Span::addNumber(unsigned int number)
{
	if (mVec.size() == N)
		throw std::runtime_error("Already N elements stored.");
	mVec.push_back(number);
}

unsigned int	Span::shortestSpan()
{
	if (mVec.size() == 0 || mVec.size() == 1)
		throw std::runtime_error("No span can be found.");
	std::vector<unsigned int> sortedVector = mVec;
	std::sort(sortedVector.begin(), sortedVector.end());

	unsigned int shortest = std::numeric_limits<unsigned int>::max();
	for (std::vector<unsigned int>::size_type i = 0; i < sortedVector.size() - 1; ++i)
	{
		unsigned int distance = sortedVector[i + 1] - sortedVector[i];
		shortest = std::min(shortest, distance);
	}
	return (shortest);
}

unsigned int	Span::longestSpan()
{
	if (mVec.size() == 0 || mVec.size() == 1)
		throw std::runtime_error("No span can be found.");
	std::pair<std::vector<unsigned int>::iterator, std::vector<unsigned int>::iterator> minMaxPair = std::minmax_element(mVec.begin(), mVec.end());

	return (*minMaxPair.second - *minMaxPair.first);
}




