/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:15:02 by sunko             #+#    #+#             */
/*   Updated: 2023/10/20 17:26:15 by sunko            ###   ########.fr       */
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
	size_t find_idx = get_line.find(s1, 0);

	if (find_idx == std::string::npos)
		return get_line;

	for (i = 0; i < get_line.length(); ++i, ++j)
	{
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
		std::cerr << "Usage : a.out <filename> <string1> <string2>\n";
		return 1;
	}

	std::string file_name = argv[1];
	std::string replace;
	size_t find_idx = file_name.find('.', 0);
	if (find_idx == std::string::npos)
		replace = file_name + ".replace";
	else
	{
		replace += file_name.substr(0, find_idx);
		replace += ".replace";
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::fstream iofile(file_name, std::ios::in | std::ios::out);
	if (!iofile)
	{
		std::cerr << "Uh oh, file could not be opened!\n";
		return 1;
	}

	std::fstream replace_file (replace, std::ios::out);
	if (!replace_file)
	{
		std::cerr << "Uh oh, file could not be opened!\n";
		return 1;
	}

	std::string get_line;
	while (std::getline(iofile, get_line))
	{
		replace_file << string_compare(s1, s2, get_line) << std::endl;
	}
	iofile.close();
	replace_file.close();
	std::cout << "clear!" << std::endl;
}
