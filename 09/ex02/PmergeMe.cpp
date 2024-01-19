/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:46:46 by sunko             #+#    #+#             */
/*   Updated: 2024/01/19 16:19:15 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

size_t PmergeMe::t[] = {
		2, 2, 6, 10, 22, 42, 86,
		170, 342, 682, 1366, 2730, 5462
};

PmergeMe::PmergeMe()
	: mVec(), mList()
{}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(const std::vector<std::pair<size_t, size_t> >& vec, const std::list<std::pair<size_t, size_t> >& list)
	: mVec(vec), mList(list)
{}


PmergeMe::PmergeMe(const PmergeMe& rhs)
	: mVec(rhs.mVec), mList(rhs.mList)
{}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this == &rhs)
		return (*this);
	mVec = rhs.mVec;
	mList = rhs.mList;
	return (*this);
}

std::vector<std::pair<size_t, size_t> > PmergeMe::mergeInsertionSort(std::vector<std::pair<size_t, size_t> > v, size_t size)
{
	if (size < 2)
		return (v);

	size_t	half = size / 2;
	bool	hasStray = size % 2;

	std::vector<std::pair<size_t, size_t> >	a;
	std::vector<std::pair<size_t, size_t> >	b;
	for (size_t i = 0; i < half; ++i)
	{
		if (v[i].first > v[i + half].first)
		{
			a.push_back(std::make_pair(v[i].first, i));
			b.push_back(std::make_pair(v[i + half].first, i));
		}
		else
		{
			a.push_back(std::make_pair(v[i + half].first, i));
			b.push_back(std::make_pair(v[i].first, i));
		}
	}
	if (hasStray)
		b.push_back(std::make_pair(v[v.size() - 1].first, half));

	// save orign vector b
	std::vector<std::pair<size_t, size_t> >	copyB(b);
	std::vector<std::pair<size_t, size_t> > sortA = mergeInsertionSort(a, a.size());

	// sw
	for (size_t i = 0; i < sortA.size(); ++i)
	{
		for (size_t j = 0; j < sortA.size(); ++j)
		{
			if (sortA[i].first == a[j].first)
				b[i] = copyB[a[j].second];
		}
	}
	// update sorting sequence
	a = sortA;
	std::vector<std::pair<size_t, size_t> > d;
	d.push_back(b[0]);
	for (size_t i = 0; i < a.size(); ++i)
		d.push_back(a[i]);

	size_t	bIdx = 1;
	size_t	k = 0;
	std::vector<std::pair<size_t, size_t> >::iterator iter;

	while (bIdx < b.size())
	{
		size_t loop = std::min(PmergeMe::t[k], b.size() - bIdx);
		for (size_t i = loop; i > 0; --i)
		{
			iter = std::upper_bound(d.begin(), d.end(), b[bIdx + i - 1]);
			d.insert(iter, b[bIdx + i - 1]);
		}
		bIdx += PmergeMe::t[k];
		k++;
	}
	return (d);
}

std::list<std::pair<size_t, size_t> > PmergeMe::mergeInsertionSort(std::list<std::pair<size_t, size_t> > list, size_t size)
{
	if (size < 2)
		return (list);

	size_t	half = size / 2;
	bool	hasStray = size % 2;

	std::list<std::pair<size_t, size_t> > a;
	std::list<std::pair<size_t, size_t> > b;
	std::list<std::pair<size_t, size_t> >::iterator iter = list.begin();
	std::list<std::pair<size_t, size_t> >::iterator halfIter = iter;
	std::advance(halfIter, half);

	for (size_t i = 0; i < half; ++i)
	{
		if (iter->first > halfIter->first)
		{
			a.push_back(std::make_pair(iter->first, i));
			b.push_back(std::make_pair(halfIter->first, i));
		}
		else
		{
			a.push_back(std::make_pair(halfIter->first, i));
			b.push_back(std::make_pair(iter->first, i));
		}
		++iter;
		++halfIter;
	}
	if (hasStray)
		b.push_back(std::make_pair((*halfIter).first, half));

	std::list<std::pair<size_t, size_t> > copyB(b);
	std::list<std::pair<size_t, size_t> > sortA = mergeInsertionSort(a, a.size());

	std::list<std::pair<size_t, size_t> >::iterator bIter = b.begin();
	std::list<std::pair<size_t, size_t> >::iterator copyBIter = copyB.begin();
	for (iter = sortA.begin(); iter != sortA.end(); ++iter)
	{
		for (halfIter = a.begin(); halfIter != a.end(); ++halfIter)
		{
			if (iter->first == halfIter->first)
			{
				std::advance(copyBIter, (*halfIter).second);
				*bIter = *copyBIter;
				copyBIter = copyB.begin();
			}
		}
		bIter++;
	}
	a = sortA;
	std::list<std::pair<size_t, size_t> > d;
	bIter = b.begin();
	d.push_back(*bIter);
	for (std::list<std::pair<size_t, size_t> >::iterator aIter = a.begin(); aIter != a.end(); ++aIter)
		d.push_back(*aIter);

	size_t	bIdx = 1;
	size_t	k = 0;
	std::list<std::pair<size_t, size_t> >::iterator insertIter;

	while (bIdx < b.size())
	{
		size_t loop = std::min(PmergeMe::t[k], b.size() - bIdx);
		std::advance(bIter, loop);
		for (size_t i = loop; i > 0; --i)
		{
			insertIter = std::upper_bound(d.begin(), d.end(), *bIter);
			d.insert(insertIter, *bIter);
			--bIter;
		}
		bIdx += PmergeMe::t[k];
		std::advance(bIter, PmergeMe::t[k]);
		k++;
	}
	return (d);
}



