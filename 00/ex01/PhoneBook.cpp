/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:05:29 by sunko             #+#    #+#             */
/*   Updated: 2023/12/25 02:27:55 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <iomanip>

PhoneBook::PhoneBook()
{
	for (int i = 0; i < 8; ++i)
		SetValid(i, 0);
}

void	PhoneBook::Add(const Contact &new_mContacts, const int cnt)
{
	if (cnt < 8)
		SetValid(cnt, 1);
	SetContact(cnt % 8, new_mContacts);
}

void	PhoneBook::Display(PhoneBook &PhoneBook)
{
	int i = 0;
	DisplayInfoRow();
	while (i < 8 && GetValid(i) == 1)
	{
		DisplayContactRow(PhoneBook.GetContact(i), i + 1);
		i++;
	}
}

void	PhoneBook::SearchIdx(PhoneBook &PhoneBook, const int idx)
{
	const int validIdx = idx - 1;
	if (!PhoneBook::IsValid(validIdx))
	{
		std::cout << "this index not vaild" << std::endl;
		return ;
	}
	DisplayInfoRow();
	DisplayContactRow(PhoneBook.GetContact(validIdx), idx);
}

bool	PhoneBook::IsValid(int idx)
{
	if (GetValid(idx))
		return true;
	else
		return false;
}

void	PhoneBook::SetValid(const int idx, const int value)
{
	mValid[idx] = value;
}

void	PhoneBook::SetContact(const int idx, const Contact &contact)
{
	mContacts[idx] = contact;
}

int	PhoneBook::GetValid(const int idx) const
{
	return (mValid[idx]);
}

const Contact	PhoneBook::GetContact(const int idx) const
{
	return (mContacts[idx]);
}

void	PhoneBook::DisplayInfoRow(void) const
{
	std::cout << std::right << std::setw(10) << "idx" << " | ";
	std::cout << std::right << std::setw(10) << "first name" << " | ";
	std::cout << std::right << std::setw(10) << "last name" << " | ";
	std::cout << std::right << std::setw(10) << "nick name" << std::endl;
}

void	PhoneBook::DisplayContactRow(Contact contact, const int idx) const
{
	std::cout << std::right << std::setw(10) << idx << " | ";
	std::cout << std::right << std::setw(10) << contact.GetFirstName() << " | ";
	std::cout << std::right << std::setw(10) << contact.GetLastName() << " | ";
	std::cout << std::right << std::setw(10) << contact.GetNickName() << std::endl;
}
