/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:39:09 by sunko             #+#    #+#             */
/*   Updated: 2024/01/11 12:27:54 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
template <typename T>
class Array
{
	private:
		T	*mArr;
		unsigned int mArrLen;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& rhs);
		Array&	operator=(const Array& rhs);
		T&		operator[](unsigned int idx);
		T		operator[](unsigned int idx) const;
		~Array();
		unsigned int	size() const;
};

template <typename T>
Array<T>::Array()
	: mArr(0), mArrLen(0)
{}

template <typename T>
Array<T>::Array(unsigned int n)
	: mArr(0), mArrLen(n)
{
	mArr = new T[n];
}

template <typename T>
Array<T>::Array(const Array& rhs)
	: mArr(0), mArrLen(rhs.mArrLen)
{
	mArr = new T[mArrLen];
	for (int i = 0; i < mArrLen; ++i)
		mArr[i] = rhs.mArr[i];
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& rhs)
{
	if (this == &rhs)
		return (*this);
	if (mArr)
		delete[] mArr;
	mArrLen = rhs.mArrLen;
	mArr = new T[mArrLen];
	for (size_t i = 0; i < mArrLen; ++i)
		mArr[i] = rhs.mArr[i];
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](unsigned int idx)
{
	if (idx < 0 || idx >= mArrLen)
		throw std::out_of_range("Index out of range");
	return mArr[idx];
}

template <typename T>
T	Array<T>::operator[](unsigned int idx) const
{
	if (idx < 0 || idx >= mArrLen)
		throw std::out_of_range("Index out of range");
	return mArr[idx];
}

template <typename T>
Array<T>::~Array()
{
	if (mArr)
		delete[] mArr;
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return mArrLen;
}

#endif
