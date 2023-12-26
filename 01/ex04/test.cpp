#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	std::string fileName("file.txt");
	size_t findIdx = fileName.find('.', 0);
	std::cout << findIdx << std::endl;
	std::string replace(fileName.substr(0, findIdx));
	replace += ".replace";

	std::cout << replace << std::endl;
	return (0);
}
