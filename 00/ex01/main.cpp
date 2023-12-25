/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:02:13 by sunko             #+#    #+#             */
/*   Updated: 2023/12/25 23:51:53 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"
#include "PhoneBook.h"

int	IsValidNumber(const std::string &str)
{
	std::string::size_type	len;

	len = str.size();
	for (std::string::size_type i = 0; i < len; ++i)
	{
		if (!std::isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	AddCmd(PhoneBook &MyBook, int &addCnt)
{
	std::string	input;
	Contact Contact;

	std::cout << "First name: ";
	input = Contact.ReadLetter();
	if (input == "")
		return (-1);
	else
		Contact.SetFirstName(input);
	std::cout << "Last name: ";
	input = Contact.ReadLetter();
	if (input == "")
		return (-1);
	else
		Contact.SetLastName(input);

	std::cout << "Phone number: ";
	input = Contact.ReadNumber();
	if (input == "")
		return (-1);
	else
		Contact.SetPhoneNumber(input);

	std::cout << "Nick name: ";
	input = Contact.ReadLetter();
	if (input == "")
		return (-1);
	else
		Contact.SetNickName(input);

	std::cout << "Nick DarkestSecret: ";
	input = Contact.ReadLetter();
	if (input == "")
		return (-1);
	else
		Contact.SetDarkestSecret(input);
	MyBook.Add(Contact, addCnt++);
	return 0;
}

int	main(void)
{
	PhoneBook	MyBook;
	int			addCnt = 0;
	int			err = 0;

	while (1)
	{
		std::string cmd;

		std::cout << "please input command (ADD, SEARCH, EXIT) : ";
		std::cin >> std::ws;
		if (!std::getline(std::cin, cmd) || cmd == "EXIT")
			break ;
		if (cmd == "ADD")
		{
			err = AddCmd(MyBook, addCnt);
			if (err == -1)
				continue;
		}
		else if (cmd == "SEARCH")
		{
			std::string idx;

			MyBook.Display(MyBook);
			std::cout << "please input index (1 ~ 8): ";

			while (std::getline(std::cin, idx))
			{
				if (IsValidNumber(idx))
				{
					int i_idx = std::stoi(idx);
					if (i_idx < 1 || i_idx > 8)
						std::cerr << "Index is only (1 ~ 8)" << std::endl;
					else
					{
						MyBook.SearchIdx(MyBook, std::stoi(idx));
						break ;
					}
				}
				else
					std::cerr << "Index is only number" << std::endl;
			}
			if (std::cin.eof())
			{
				std::cerr << "EOF" << std::endl;
				std::clearerr(stdin);
				std::cin.clear();
			}
		}
		else
			std::cout << "not found this command!" << std::endl;
	}
	std::cout << "program quits" << std::endl;
	return 0;
}
