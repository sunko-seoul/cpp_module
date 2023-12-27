/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:15:02 by sunko             #+#    #+#             */
/*   Updated: 2023/12/27 23:07:29 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

std::string getReplaceString(const std::string &s1, const std::string &s2, std::string buffer)
{
	std::string				result;
	std::string				temp;
	std::size_t				findIdx = buffer.find(s1);

	if (findIdx == std::string::npos)
		return (buffer);
	while (1)
	{
		result.append(buffer, 0, findIdx);
		result += s2;
		buffer.erase(0, findIdx + s1.length());
		findIdx = buffer.find(s1);
		if (findIdx == std::string::npos)
		{
			result += buffer;
			break ;
		}
	}
	return result;
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage : a.out <filename> <string1> <string2>" << std::endl;
		return (1);
	}

	std::string fileName = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string replaceFileName;

	size_t findIdx = fileName.find('.', 0);
	if (findIdx == std::string::npos)
		replaceFileName = fileName + ".replace";
	else
	{
		replaceFileName += fileName.substr(0, findIdx);
		replaceFileName += ".replace";
	}

	std::fstream originFile(fileName, std::fstream::in | std::fstream::out);
	if (originFile.fail())
	{
		std::cerr << fileName << " could not be opened!" << std::endl;
		return 1;
	}

	std::fstream replaceFile(replaceFileName, std::fstream::out);
	if (replaceFile.fail())
	{
		std::cerr << replaceFileName << " could not be opened!" << std::endl;
		return 1;
	}

	std::string buffer;
	while (std::getline(originFile, buffer))
		replaceFile << getReplaceString(s1, s2, buffer) << std::endl;
	std::cout << "clear!" << std::endl;
}
