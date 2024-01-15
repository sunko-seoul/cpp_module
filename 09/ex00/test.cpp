#include <iostream>
#include <sstream>

int main(void)
{
	std::string line("2009-01-0232.023sdsdfgd23adsa");

	std::string::iterator iter = std::find(line.begin(), line.end(), ',');
	if (iter == line.end())
	{
		std::cerr << "error" << std::endl;
		exit(1);
	}
	std::string data(line.begin(), iter);
	std::string value(iter + 1, line.end());
	std::istringstream	iss(value);
	std::cout << "data : " << data << std::endl;
	std::cout << "value : " << value << std::endl;

	double double_value;

	iss >> double_value;

	std::cout << "double_value : " << double_value << std::endl;

	std::cout << iss << std::endl;
}
