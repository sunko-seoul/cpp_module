/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:05:04 by sunko             #+#    #+#             */
/*   Updated: 2023/10/16 14:45:06 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

Contact::Contact()
{
	std::cout << "first name : ";
	std::cin >> std::ws;
	std::getline(std::cin, Contact::first_name);

	std::cout << "last name : ";
	std::cin >> std::ws;
	std::getline(std::cin, Contact::last_name);

	std::cout << "nick name : ";
	std::cin >> std::ws;
	std::getline(std::cin, Contact::nick_name);

	std::cout << "phone number : ";
	std::cin >> std::ws;
	std::getline(std::cin, Contact::phone_number);

	std::cout << "darkset_secret : ";
	std::cin >> std::ws;
	std::getline(std::cin, Contact::darkest_secret);
}

Contact::~Contact()
{
	std::cout << "Lost " << Contact::first_name << " contact.";
}

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

void	Contact::set_first_name(std::string s)
{
	first_name = s;
}

void	Contact::set_last_name(std::string s)
{
	last_name = s;
}

void	Contact::set_nick_name(std::string s)
{
	nick_name = s;
}

void	Contact::set_phone_number(std::string s)
{
	phone_number = s;
}

void	Contact::set_darkest_secret(std::string s)
{
	darkest_secret = s;
}


