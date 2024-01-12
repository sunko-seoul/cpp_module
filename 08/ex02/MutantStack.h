/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:46:57 by sunko             #+#    #+#             */
/*   Updated: 2024/01/12 16:02:28 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_H
# define MUTANT_STACK_H

# include <stack>
template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack& rhs);
		MutantStack&	operator=(const MutantStack& rhs);
		class iterator
		{
			private:
				T*	mPtr;
				iterator();
			public:
				iterator(T* ptr);
				iterator(const iterator& rhs);
				iterator&	operator=(const iterator& rhs);
				~iterator();
				T&	operator*() const;
				iterator	operator++();
				iterator	operator++(int);
				iterator	operator--();
				iterator	operator--(int);
				bool		operator!=(const iterator& rhs) const;
		};
		iterator	begin();
		iterator	end();
};

template <typename T>
MutantStack<T>::MutantStack()
	: std::stack<T>()
{}

template <typename T>
MutantStack<T>::~MutantStack()
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& rhs)
	: std::stack<T>(rhs)
{}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack& rhs)
{
	if (this == &rhs)
		return (*this);
	std::stack<T>::operator=(rhs);
}

template <typename T>
MutantStack<T>::iterator::iterator()
	: mPtr(0)
{}

template <typename T>
MutantStack<T>::iterator::iterator(T* ptr)
	: mPtr(ptr)
{}

template <typename T>
MutantStack<T>::iterator::iterator(const iterator& rhs)
	: mPtr(rhs.mPtr)
{}

template <typename T>
typename MutantStack<T>::iterator&	MutantStack<T>::iterator::operator=(const iterator& rhs)
{
	if (this == &rhs)
		return (*this);
	mPtr = rhs.mPtr;
	return (*this);
}

template <typename T>
MutantStack<T>::iterator::~iterator()
{}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (iterator(&this->c.front()));
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (iterator(&this->c.back() + 1));
}

template <typename T>
T&	MutantStack<T>::iterator::operator*() const
{
	return *mPtr;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++()
{
	++mPtr;
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++(int)
{
	iterator temp = *this;
	++mPtr;
	return (temp);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--()
{
	--mPtr;
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--(int)
{
	iterator temp = *this;
	--mPtr;
	return (temp);
}

template <typename T>
bool	MutantStack<T>::iterator::operator!=(const iterator& rhs) const
{
	return (mPtr != rhs.mPtr);
}





#endif
