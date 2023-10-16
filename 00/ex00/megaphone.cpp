#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			std::string s(argv[i]);
			for (std::string::size_type j = 0; j < s.size(); j++)
			{
				if (isalpha(s[j]))
					std::cout << static_cast<char>(toupper(s[j]));
				else
					std::cout << s[j];
			}
		}
	}
	std::cout << std::endl;
	return 0;
}
