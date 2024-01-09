#include <iostream>
#include <cstdlib>
#include <limits>

bool tryParseInt(const std::string& str, int& result) {
    char* end;
    long longValue = std::strtol(str.c_str(), &end, 10);

    // 변환 성공 여부 및 전체 문자열 변환이 완료되었는지 확인
	std::cout << longValue << std::endl;
    if (*end == '\0' && longValue >= std::numeric_limits<int>::min() && longValue <= std::numeric_limits<int>::max()) {
        result = static_cast<int>(longValue);
        return true;
    } else {
        return false;
    }
}

int main() {
    std::string str = "sdsadsa";
    int result;

    if (tryParseInt(str, result)) {
        std::cout << "Converted integer: " << result << std::endl;
    } else {
        std::cerr << "Overflow or invalid argument occurred." << std::endl;
    }

    return 0;
}
