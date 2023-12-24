#include <string>
#include <iostream>

int main(void)
{
  std::string s;

  while (std::getline(std::cin, s))
  {
    std::cout << "You entered:" << s << '\n';
  }
  std::cout << "last" << s << '\n';
}
