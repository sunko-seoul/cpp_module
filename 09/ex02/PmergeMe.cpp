/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:46:46 by sunko             #+#    #+#             */
/*   Updated: 2024/01/21 00:42:58 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const size_t PmergeMe::Diff[] = {
	2, 2, 6, 10, 22, 42, 86,
	170, 342, 682, 1366, 2730, 5462
};

const size_t PmergeMe::Jacob[] = {
	1, 3, 5, 11, 21, 43, 85, 171,
	341, 683, 1365, 2731, 5461
};

PmergeMe::PmergeMe()
	: mVec(), mQue()
{}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(const std::vector<int>& vec, const std::deque<int>& deque)
	: mVec(vec), mQue(deque)
{}


PmergeMe::PmergeMe(const PmergeMe& rhs)
	: mVec(rhs.mVec), mQue(rhs.mQue)
{}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this == &rhs)
		return (*this);
	mVec = rhs.mVec;
	mQue = rhs.mQue;
	return (*this);
}

int	PmergeMe::findMappingB(std::vector<std::pair<int, int> >& storeVec, int val)
{
	for (std::vector<std::pair<int, int> >::iterator iter = storeVec.begin(); iter != storeVec.end(); ++iter)
	{
		if ((*iter).first == val)
		{
			int ret = (*iter).second;
			storeVec.erase(iter);
			return (ret);
		}
	}
	return (0);
}

int	PmergeMe::findMappingB(std::deque<std::pair<int, int> >& storeQue, int val)
{
	for (std::deque<std::pair<int, int> >::iterator iter = storeQue.begin(); iter != storeQue.end(); ++iter)
	{
		if ((*iter).first == val)
		{
			int ret = (*iter).second;
			storeQue.erase(iter);
			return (ret);
		}
	}
	return (0);
}

std::vector<int> PmergeMe::mergeInsertionSort(std::vector<int> v, size_t size)
{
	if (size < 2)
		return v;
	size_t	half = v.size() / 2;
	bool	isOdd = v.size() % 2;
	std::vector<int> a;
	std::vector<int> b;

	for (size_t i = 0; i < half; ++i)
	{
		if (v[i] > v[i + half])
		{
			a.push_back(v[i]);
			b.push_back(v[i + half]);
		}
		else
		{
			a.push_back(v[i + half]);
			b.push_back(v[i]);
		}
	}
	if (isOdd)
		b.push_back(v[v.size() - 1]);
	std::vector<std::pair<int, int> > storeVec;
	for (size_t i = 0; i < half; ++i)
		storeVec.push_back(std::make_pair(a[i], b[i]));
	a = mergeInsertionSort(a, a.size());
	for (size_t i = 0; i < half; ++i)
		b[i] = findMappingB(storeVec, a[i]);
	std::vector<int> d;
	d.push_back(b[0]);
	for (size_t i = 0; i < half; ++i)
		d.push_back(a[i]);
	int k = 1;
	std::vector<int>::iterator insertIt;
	std::vector<int>::iterator searchEndIt;
	while (PmergeMe::Jacob[k-1] < half)
	{
		int m = std::min(PmergeMe::Jacob[k]-1, half-1); // first insert index
		int u = PmergeMe::Jacob[k-1] + m; // position of Am in d
		for (size_t i = m; i >= PmergeMe::Jacob[k-1]; --i)
		{
			searchEndIt = std::next(d.begin(), u);
			insertIt = std::upper_bound(d.begin(), searchEndIt, b[i]);
			d.insert(insertIt, b[i]);
			while (d[u] != a[i-1])
				--u;
		}
		k++;
	}
	if (isOdd)
	{
		insertIt = std::upper_bound(d.begin(), d.end(), *(std::prev(b.end())));
		d.insert(insertIt, *(std::prev(b.end())));
	}
	return (d);
}

std::deque<int> PmergeMe::mergeInsertionSort(std::deque<int> v, size_t size)
{
	if (size < 2)
		return v;
	size_t	half = v.size() / 2;
	bool	isOdd = v.size() % 2;
	std::deque<int> a;
	std::deque<int> b;

	for (size_t i = 0; i < half; ++i)
	{
		if (v[i] > v[i + half])
		{
			a.push_back(v[i]);
			b.push_back(v[i + half]);
		}
		else
		{
			a.push_back(v[i + half]);
			b.push_back(v[i]);
		}
	}
	if (isOdd)
		b.push_back(v[v.size() - 1]);
	std::deque<std::pair<int, int> > storeQue;
	for (size_t i = 0; i < half; ++i)
		storeQue.push_back(std::make_pair(a[i], b[i]));
	a = mergeInsertionSort(a, a.size());
	for (size_t i = 0; i < half; ++i)
		b[i] = findMappingB(storeQue, a[i]);
	std::deque<int> d;
	d.push_back(b[0]);
	for (size_t i = 0; i < half; ++i)
		d.push_back(a[i]);
	int k = 1;
	std::deque<int>::iterator insertIt;
	std::deque<int>::iterator searchEndIt;
	while (PmergeMe::Jacob[k-1] < half)
	{
		int m = std::min(PmergeMe::Jacob[k]-1, half-1); // first insert index
		int u = PmergeMe::Jacob[k-1] + m; // position of Am in d
		for (size_t i = m; i >= PmergeMe::Jacob[k-1]; --i)
		{
			searchEndIt = std::next(d.begin(), u);
			insertIt = std::upper_bound(d.begin(), searchEndIt, b[i]);
			d.insert(insertIt, b[i]);
			while (d[u] != a[i-1])
				--u;
		}
		k++;
	}
	if (isOdd)
	{
		insertIt = std::upper_bound(d.begin(), d.end(), *(std::prev(b.end())));
		d.insert(insertIt, *(std::prev(b.end())));
	}
	return (d);
}







