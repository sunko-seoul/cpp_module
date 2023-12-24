/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:05:04 by sunko             #+#    #+#             */
/*   Updated: 2023/12/25 02:18:03 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

std::string	Contact::GetFirstName(void)
{
	return mFirstName;
}

std::string	Contact::GetLastName(void)
{
	return mLastName;
}

std::string	Contact::GetNickName(void)
{
	return mNickName;
}

std::string	Contact::GetPhoneNumber(void)
{
	return mPhoneNumber;
}

std::string	Contact::GetDarkestSecret(void)
{
	return mDarkestSecret;
}

void	Contact::SetFirstName(const std::string &str)
{
	mFirstName = str;
}

void	Contact::SetLastName(const std::string &str)
{
	mLastName = str;
}

void	Contact::SetNickName(const std::string &str)
{
	mNickName = str;
}

void	Contact::SetPhoneNumber(const std::string &str)
{
	mPhoneNumber = str;
}

void	Contact::SetDarkestSecret(const std::string &str)
{
	mDarkestSecret = str;
}

int	Contact::IsValidLetter(const std::string &str)
{
	std::string::size_type	len;

	len = str.size();
	for (std::string::size_type i = 0; i < len; ++i)
	{
		if (!std::isalnum(str[i]))
			return (0);
	}
	return (1);
}

int	Contact::IsValidNumber(const std::string &str)
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

const std::string	Contact::ReadLetter(void)
{
	std::string	input;

	std::cin >> std::ws;
	while (std::getline(std::cin, input))
	{
		if (IsValidLetter(input))
		{
			if (input.size() > 10)
			{
				input = input.substr(0, 10);
				input[9] = '.';
			}
			return (input);
		}
		else
			std::cerr << "This type is consists of only alphabets" << std::endl;
	}
	std::cerr << "EOF" << std::endl;
	return ("");
}

const std::string	Contact::ReadNumber(void)
{
	std::string	input;

	std::cin >> std::ws;
	while (std::getline(std::cin, input))
	{
		if (IsValidNumber(input))
		{
			if (input.size() > 10)
			{
				input = input.substr(0, 10);
				input[9] = '.';
			}
			return (input);
		}
		else
			std::cerr << "This type is consists of only numbers" << std::endl;
	}
	std::cerr << "EOF" << std::endl;
	return ("");
}
