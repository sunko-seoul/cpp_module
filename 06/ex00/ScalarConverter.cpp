/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:54:38 by sunko             #+#    #+#             */
/*   Updated: 2024/01/10 10:33:49 by sunko            ###   ########.fr       */
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
#include <iomanip>
#define	CHAR		0
#define	INT			1
#define	FLOAT		2
#define	DOUBLE		3
#define NOT_NUMBER	4
#define INF			5
#define ERROR		6

// 1. detect the type of the literal passed parameter.
// 2. convert it string to its actual type;



ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}

void	ScalarConverter::printFloatToOtherType(double value)
{
	/* char */
	std::cout << "char: ";
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
			std::cout << "Overflow" << std::endl;
	else
	{
		char charType = static_cast<char>(value);
		if (std::isprint(charType))
			std::cout <<  charType << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}

	/* int */
	std::cout << "int: ";
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "Overflow" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;

	/* float */
	std::cout << "float: ";
	if (value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
		std::cout << "Overflow" << std::endl;
	else
		std::cout << std::setprecision(10) <<  value << "f" <<  std::endl;

	/* double */
	std::cout << "double: ";
	if (value < std::numeric_limits<double>::min() || value > std::numeric_limits<double>::max())
		std::cout << "Overflow" << std::endl;
	else
		std::cout << std::setprecision(10) <<  value << std::endl;
}

void	ScalarConverter::printIntTotherType(long long value)
{
	/* char */
	std::cout << "char: ";
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
			std::cout << "Overflow" << std::endl;
	else
	{
		char charType = static_cast<char>(value);
		if (std::isprint(charType))
			std::cout <<  charType << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}

	/* int */
	std::cout << "int: ";
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "Overflow" << std::endl;
	else
		std::cout << value << std::endl;

	/* float */
	double	doubleValue = static_cast<double>(value);
	std::cout << "float: ";
	if (doubleValue < std::numeric_limits<float>::min() || doubleValue > std::numeric_limits<float>::max())
		std::cout << "Overflow" << std::endl;
	else
		std::cout << std::setprecision(10) << doubleValue << ".0f" << std::endl;

	/* double */
	std::cout << "double: ";
	if (doubleValue < std::numeric_limits<double>::min() || doubleValue > std::numeric_limits<double>::max())
		std::cout << "Overflow" << std::endl;
	std::cout << std::setprecision(10) << doubleValue << ".0" << std::endl;
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

bool	ScalarConverter::tryParseInt(const std::string& s)
{
	char*	end;

	std::strtoll(s.c_str(), &end, 10);
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

bool	ScalarConverter::tryParseError(const std::string& s)
{
	int	dotCnt = 0;
	for (size_t i = 0; i < s.length(); ++i)
	{
		if (std::isalpha(s[i]) && i != s.length() - 1)
			return (true);
		if (s[i] == '.')
			dotCnt++;
		if ((s[i] == 'f' || s[i] == 'F') && i != s.length() - 1)
			return (true);
	}
	if (dotCnt > 1)
		return (true);
	return (false);
}

// detect the type of the literal passed parameter.
int		ScalarConverter::detectType(std::string s)
{
	if (tryParseChar(s))
		return (CHAR);
	if (tryParseError(s))
		return (ERROR);
	if (s.find('.') != std::string::npos)
	{
		if (s.back() == 'f')
			return (FLOAT);
		else
			return (DOUBLE);
	}
	if (s.find('.') == std::string::npos)
	{
		if (tryParseInt(s))
			return (INT);
	}
	if (s == "nan" || s == "nanf")
		return (NOT_NUMBER);
	if (s == "-inff" || s == "+inff" || s == "-inf" || s == "+inf")
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
		long long	llValue = std::strtoll(s.c_str(), 0, 10);
		converter.printIntTotherType(llValue);
	}
	else if (type == FLOAT)
	{
		if (trimStr.back() == 'f' || trimStr.back() == 'F')
			trimStr.pop_back();
		std::stringstream	ssf(trimStr);
		double floatValue;
		ssf >> floatValue;
		converter.printFloatToOtherType(floatValue);
	}
	else if (type == DOUBLE)
	{
		std::stringstream	ssd(trimStr);
		double doubleValue;
		ssd >> doubleValue;
		converter.printFloatToOtherType(doubleValue);
	}
	else if (type == NOT_NUMBER)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (type == INF)
	{
		trimStr.erase(trimStr.begin() + 4);
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << trimStr + "f" << std::endl;
		std::cout << "double: " << trimStr << std::endl;
	}
	else if (type == ERROR)
	{
		std::cout << "Error" << std::endl;
	}
}
