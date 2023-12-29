#include <iostream>
#include <cmath>

int	main(void)
{
	// 부동 소수점 => 고정 소수점
	{
		float	floatingPointNumber = 3.14159;
		int		fixedPointNumber = static_cast<int>(floatingPointNumber * 100);
		fixedPointNumber = static_cast<int>(std::round(fixedPointNumber));

		std::cout << "floating point : " << floatingPointNumber << std::endl;
		std::cout << "fixed point : " << fixedPointNumber << std::endl;
	}


	// 고정 소수점=> 부동 소수점
	{
		int	fixedPointNumber = 314;
		float floatingPointNumber = static_cast<float>(fixedPointNumber) / 100;

		std::cout << "floating point : " << floatingPointNumber << std::endl;
		std::cout << "fixed point : " << fixedPointNumber << std::endl;
	}

	{
		int	fixedPointNumber = 314;
		int	integerPart = fixedPointNumber / 100;

		std::cout << "fixed point : " << fixedPointNumber << std::endl;
		std::cout << "integer part : " << integerPart << std::endl;
	}

	return (0);
}
