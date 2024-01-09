/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:54:38 by sunko             #+#    #+#             */
/*   Updated: 2024/01/09 12:14:55 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits>
#define	CHAR		0
#define	INT			1
#define	FLOAT		2
#define	DOUBLE		3
#define NAN			4
#define INF			5
#define LONG LONG	6
#define ERROR		7

// 1. detect the type of the literal passed parameter.
// 2. convert it string to its actual type;



ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}

bool	ScalarConverter::tryParseInt(const std::string& s, long long& result)
{
	char*	end;
	result = std::strtol(s.c_str(), &end, 10);

	if (*end == '\0')
		return (true);
	else
		return (false);
}

bool	ScalarConverter::tryParseChar(const std::string& s)
{
	if (s.length() == 1)
	{
		char charType = static_cast<char>(s[0]);
		return (charType >= 0 && charType <= 127);
	}
	return (false);
}

// detect the type of the literal passed parameter.
int		ScalarConverter::detectType(sted::string s)
{
	if (tryParseInt(s))
		return (CHAR);
	else if (str.find('.') != std::string::npos)
	{

	}
	else if (str.find('.') == std::string::npos)
	{
		long long llValue;
		if (tryParseInt(s, llValue))
		{
			if (llValue >= std::numeric_limits<int>::min() && llValue <= std::numeric_limits<int>::max())
				return (INT);
			else
				return (LONG LONG);
		}
	}
	else if (s == "nan" || s == "nanf")
		return (NAN);
	else if (s == "-inff" || s == "+inff" || s == "-inf" || s == "inf")
		return (INF);
}

std::string	ScalarConverter::trimWhiteSpace(const std::string& s)
{
	size_t	start = 0;
	size_t	end = s.length();

	while (start < end && std::isspace(s[start]))
		++start;
	while (end > start && std::isspace(s[end - 1]))
		--end;
	return (s.substr(start, end - start));
}

void	ScalarConverter::convert(std::string s)
{
	ScalarConverter	converter;
	std::string trimStr = converter.trimWhiteSpace(s);
	std::cout << trimStr << std::endl;


}
