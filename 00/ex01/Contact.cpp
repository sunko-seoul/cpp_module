/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:05:04 by sunko             #+#    #+#             */
/*   Updated: 2023/10/16 17:15:25 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

Contact::Contact(){}

Contact::~Contact(){}

Contact::Contact(const Contact &other)
{
	if (&other != this)
	{
		this->first_name = other.first_name;
		this->last_name = other.last_name;
		this->nick_name = other.nick_name;
		this->phone_number = other.phone_number;
		this->darkest_secret = other.darkest_secret;
	}
}

Contact&	Contact::operator=(const Contact &other)
{
	if (this != &other)
	{
		this->first_name = other.first_name;
		this->last_name = other.last_name;
		this->nick_name = other.nick_name;
		this->phone_number = other.phone_number;
		this->darkest_secret = other.darkest_secret;
	}
	return *this;
}

std::string	Contact::get_first_name(void)
{
	return first_name;
}

std::string Contact::get_last_name(void)
{
	return last_name;
}

std::string Contact::get_nick_name(void)
{
	return nick_name;
}

std::string Contact::get_phone_number(void)
{
	return phone_number;
}

std::string Contact::get_darkset_secret(void)
{
	return darkest_secret;
}

int	Contact::set_first_name(void)
{
	std::string s;

	std::cout << std::setw(10) << "first name : ";
	std::cin >> std::ws;
	if (!std::getline(std::cin, s))
	{
		std::cerr << "getline error!" << std::endl;
		return EXIT_FAILURE;
	}
	std::string::size_type len = s.size();
	for (std::string::size_type i = 0; i < len; ++i)
	{
		if (!std::isalnum(s[i]))
		{
			std::cout << "first name consists of only numbers and alphabets" << std::endl;
			return -1;
		}
	}
	if (len > 10)
	{
		first_name = s.substr(0, 10);
		s[9] = '.';
		return 0;
	}
	first_name = s;
	return 0;
}

int	Contact::set_last_name(void)
{
	std::string s;

	std::cout << "last name : ";
	std::cin >> std::ws;
	if (!std::getline(std::cin, s))
	{
		std::cerr << "getline error!" << std::endl;
		return EXIT_FAILURE;
	}
	std::string::size_type len = s.size();
	for (std::string::size_type i = 0; i < len; ++i)
	{
		if (!std::isalnum(s[i]))
		{
			std::cout << "last name consists of only numbers and alphabets" << std::endl;
			return -1;
		}
	}
	if (len > 10)
	{
		last_name = s.substr(0, 10);
		s[9] = '.';
		return 0;
	}
	last_name = s;
	return 0;
}

int	Contact::set_nick_name(void)
{
	std::string s;

	std::cout << "nick name : ";
	std::cin >> std::ws;
	if (!std::getline(std::cin, s))
	{
		std::cerr << "getline error!" << std::endl;
		return EXIT_FAILURE;
	}
	std::string::size_type len = s.size();
	for (std::string::size_type i = 0; i < len; ++i)
	{
		if (!std::isalnum(s[i]))
		{
			std::cout << "nick name consists of only numbers and alphabets" << std::endl;
			return -1;
		}
	}
	if (len > 10)
	{
		nick_name = s.substr(0, 10);
		s[9] = '.';
		return 0;
	}
	nick_name = s;
	return 0;
}

int	Contact::set_phone_number(void)
{
	std::string s;

	std::cout << "phone number : ";
	std::cin >> std::ws;
	if (!std::getline(std::cin, s))
	{
		std::cerr << "getline error!" << std::endl;
		return EXIT_FAILURE;
	}
	std::string::size_type len = s.size();
	for (std::string::size_type i = 0; i < len; ++i)
	{
		if (!std::isdigit(s[i]))
		{
			std::cout << "phone number consists of only numbers" << std::endl;
			return -1;
		}
	}
	if (len > 10)
	{
		phone_number = s.substr(0, 10);
		s[9] = '.';
		return 0;
	}
	phone_number = s;
	return 0;
}

int	Contact::set_darkest_secret(void)
{
	std::string s;

	std::cout << "darkset_secret : ";
	std::cin >> std::ws;
	if (!std::getline(std::cin, s))
	{
		std::cerr << "getline error!" << std::endl;
		return EXIT_FAILURE;
	}
	std::string::size_type len = s.size();
	for (std::string::size_type i = 0; i < s.size(); ++i)
	{
		if (!std::isalnum(s[i]))
		{
			std::cout << "nick name consists of only numbers and alphabets" << std::endl;
			return -1;
		}
	}
	if (len > 10)
	{
		darkest_secret = s.substr(0, 10);
		s[9] = '.';
		return 0;
	}
	darkest_secret = s;
	return 0;
}


