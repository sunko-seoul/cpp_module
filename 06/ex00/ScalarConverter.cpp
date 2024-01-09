/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:54:38 by sunko             #+#    #+#             */
/*   Updated: 2024/01/09 22:44:32 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <locale>
#define	CHAR		0
#define	INT			1
#define	FLOAT		2
#define	DOUBLE		3
#define NOT_NUMBER	4
#define INF			5
#define LONGLONG	6
#define ERROR		7

// 1. detect the type of the literal passed parameter.
// 2. convert it string to its actual type;



ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}

void	ScalarConverter::printIntTotherType(int value)
{
	char	charType = static_cast<char>(value);
	std::cout << "char: ";
	if (std::isprint(charType))
		std::cout <<  charType << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout <<"int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void	ScalarConverter::printCharToOtherType(char value)
{
	std::cout << "char: ";
	if (!std::isprint(value))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << value << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

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
		if ((charType >= 0 && charType <= 127) \
		&& !(charType >= 48 && charType <= 57))
			return (true);
	}
	return (false);
}

// detect the type of the literal passed parameter.
int		ScalarConverter::detectType(std::string s)
{
	if (tryParseChar(s))
		return (CHAR);
	else if (s.find('.') != std::string::npos)
	{
		if (s.back() == 'f')
			return (FLOAT);
		else
			return (DOUBLE);
	}
	else if (s.find('.') == std::string::npos)
	{
		long long llValue;
		if (tryParseInt(s, llValue))
		{
			if (llValue >= std::numeric_limits<int>::min() && llValue <= std::numeric_limits<int>::max())
				return (INT);
			else
				return (LONGLONG);
		}
	}
	else if (s == "nan" || s == "nanf")
		return (NOT_NUMBER);
	else if (s == "-inff" || s == "+inff" || s == "-inf" || s == "inf")
		return (INF);
	return (ERROR);
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
	int	type = converter.detectType(trimStr);

	if (type == CHAR)
	{
		char charValue = static_cast<char>(trimStr[0]);
		converter.printCharToOtherType(charValue);
	}
	else if (type == INT)
	{
		int intValue = std::atoi(trimStr.c_str());
		converter.printIntTotherType(intValue);
	}
	else if (type == FLOAT)
	{
		std::cout << "trimStr = " << trimStr << std::endl;
		if (trimStr.back() == 'f' || trimStr.back() == 'F')
			trimStr.pop_back();
		std::stringstream	ssf(trimStr);
		float floatValue;
		ssf >> floatValue;
		if (!ssf.fail() && \
		(floatValue > std::numeric_limits<float>::max() || floatValue < std::numeric_limits<float>::min()))
		{
			// handle overflow
		}
		std::cout << "floatValue = " << floatValue << "f" << std::endl;
		// convertFloatToOtherType()
	}
	else if (type == DOUBLE)
	{
		std::stringstream	ssd(trimStr);
		double doubleValue;
		ssd >> doubleValue;
		if (!ssd.fail() && \
		(doubleValue > std::numeric_limits<double>::max() || doubleValue < std::numeric_limits<double>::min()))
		{
			// handle overflow
		}
		std::cout << "doubleValue = " << doubleValue << std::endl;
		// convertDoubleToOtherType()
	}
}
