/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:15:02 by sunko             #+#    #+#             */
/*   Updated: 2023/12/26 23:11:58 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

std::string string_compare(const std::string &s1, const std::string &s2, std::string get_line)
{
	std::string result;
	std::string temp;
	std::string::size_type i = 0;
	std::string::size_type j = 0;
	std::string::size_type s1_len = s1.length();
	std::string::size_type s2_len = s2.length();
	size_t findIdx = get_line.find(s1, 0);

	if (findIdx == std::string::npos)
		return get_line;

	for (i = 0; i < get_line.length(); ++i, ++j)
	{
		//if (get_line.find(s1, i) != std::string::npos)
		if (s1[0] == get_line[i] && s1.compare(0, s1.length(), get_line, i, s1.length()) == 0)
		{
			result += s2;
			j += s2_len - 1;
			i += s1_len - 1;
		}
		else
			result += get_line[i];
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

	std::fstream iofile(fileName, std::ios::in | std::ios::out);
	if (!iofile)
	{
		std::cerr << fileName << " could not be opened!" << std::endl;
		return 1;
	}

	std::fstream replaceFile (replaceFileName, std::ios::out);
	if (!replaceFile)
	{
		std::cerr << replaceFileName << " could not be opened!" << std::endl;
		return 1;
	}

	std::string get_line;
	while (std::getline(iofile, get_line))
	{
		replaceFile << string_compare(s1, s2, get_line) << std::endl;
	}
	iofile.close();
	replaceFile.close();
	std::cout << "clear!" << std::endl;
}
