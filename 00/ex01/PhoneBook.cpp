/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:05:29 by sunko             #+#    #+#             */
/*   Updated: 2023/10/16 17:32:58 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <iomanip>

PhoneBook::PhoneBook()
{
	for (int i = 0; i < 8; ++i)
		valid[i] = 0;
}

PhoneBook::~PhoneBook(){};

PhoneBook::PhoneBook(const PhoneBook &other)
{
	if (this != &other)
	{
		int i = 0;
		while (i <= 7 && valid[i] == 1)
		{
			PhoneBook::contact[i] = other.contact[i];
			i++;
		}
	}
}

PhoneBook& PhoneBook::operator=(const PhoneBook &other)
{
	if (this != &other)
	{
		int i = 0;
		while (i <= 7 && valid[i] == 1)
		{
			PhoneBook::contact[i] = other.contact[i];
			i++;
		}
	}
	return *this;
}

void	PhoneBook::Add(Contact &new_contact, int cnt)
{
	if (cnt < 8)
		valid[cnt] = 1;
	contact[cnt % 8] = new_contact;
}


void	PhoneBook::Display(void)
{
	int i = 0;
	std::cout << std::right << std::setw(10) << "idx" << " | ";
	std::cout << std::right << std::setw(10) << "first name" << " | ";
	std::cout << std::right << std::setw(10) << "last name" << " | ";
	std::cout << std::right << std::setw(10) << "nick name" << std::endl;
	while (i <= 7 && valid[i] == 1)
	{
		std::cout << std::right << std::setw(10) << i + 1 << " | ";
		std::cout << std::right << std::setw(10) << contact[i].get_first_name() << " | ";
		std::cout << std::right << std::setw(10) << contact[i].get_last_name() << " | ";
		std::cout << std::right << std::setw(10) << contact[i].get_nick_name() << std::endl;
		i++;
	}
}

void	PhoneBook::Search_idx(int idx)
{
	idx--;
	if (!PhoneBook::isValid(idx))
	{
		std::cout << "this index not vaild\n";
		return ;
	}
	std::cout << std::right << std::setw(10) << "idx" << " | ";
	std::cout << std::right << std::setw(10) << "first name" << " | ";
	std::cout << std::right << std::setw(10) << "last name" << " | ";
	std::cout << std::right << std::setw(10) << "nick name" << std::endl;

	std::cout << std::right << std::setw(10) << idx << " | ";
	std::cout << std::right << std::setw(10) << contact[idx].get_first_name() << " | ";
	std::cout << std::right << std::setw(10) << contact[idx].get_last_name() << " | ";
	std::cout << std::right << std::setw(10) << contact[idx].get_nick_name() << std::endl;
}

bool	PhoneBook::isValid(int idx)
{
	if (valid[idx])
		return true;
	else
		return false;
}

