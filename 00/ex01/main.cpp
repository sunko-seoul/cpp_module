/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:02:13 by sunko             #+#    #+#             */
/*   Updated: 2023/10/16 17:29:39 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"
#include "PhoneBook.h"

int	add_cmd(PhoneBook &MyBook, int add_cnt)
{
	Contact NewContact;
	int		err_num;

	err_num = NewContact.set_first_name();
	if (err_num == -1)
		return -1;
	else if (err_num == EXIT_FAILURE)
		return EXIT_FAILURE;

	err_num = NewContact.set_last_name();
	if (err_num == -1)
		return -1;
	else if (err_num == EXIT_FAILURE)
		return EXIT_FAILURE;

	err_num = NewContact.set_nick_name();
	if (err_num == -1)
		return -1;
	else if (err_num == EXIT_FAILURE)
		return EXIT_FAILURE;

	err_num = NewContact.set_phone_number();
	if (err_num == -1)
		return -1;
	else if (err_num == EXIT_FAILURE)
		return EXIT_FAILURE;

	err_num = NewContact.set_darkest_secret();
	if (err_num == -1)
		return -1;
	else if (err_num == EXIT_FAILURE)
		return EXIT_FAILURE;

	MyBook.Add(NewContact, add_cnt++);
	return 0;
}


int	main(void)
{
	PhoneBook	MyBook;
	int			add_cnt = 0;
	int			err_num = 0;

	while (1)
	{
		std::string cmd;

		std::cout << "please input command (ADD, SEARCH, EXIT) : ";
		std::cin >> std::ws;
		if (!std::getline(std::cin, cmd))
		{
			std::cerr << "getline error!" << std::endl;
			return EXIT_FAILURE;
		}
		if (cmd == "EXIT")
			break ;
		else if (cmd == "ADD")
		{
			err_num = add_cmd(MyBook, add_cnt);
			if (err_num == -1)
				continue;
			else if (err_num == EXIT_FAILURE)
				return EXIT_FAILURE;
		}
		else if (cmd == "SEARCH")
		{
			char idx;
			MyBook.Display();
			std::cout << "please input index : ";
			std::cin >> idx;
			std::cout << "idx = " << idx << " isdisit(idx) : " << isdigit(idx) << std::endl;
			if (!isdigit(idx))
			{
				std::cout << "index consist of only numbers" << std::endl;
				continue;
			}
			MyBook.Search_idx(idx - '0');
		}
		else
			std::cout << "not found this command!" << std::endl;
	}
	std::cout << "program quits" << std::endl;
	return 0;
}
