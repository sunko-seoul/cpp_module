#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main() {
    // 랜덤 시드 설정
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // 출력 파일 열기
    std::ofstream outputFile("output.txt");

    if (!outputFile.is_open()) {
        std::cerr << "파일을 열 수 없습니다." << std::endl;
        return 1;
    }

    // 100줄의 알파벳 문장 생성 및 파일에 쓰기
    for (int i = 0; i < 100; ++i) {
        // 각 줄에 랜덤한 횟수로 "apple" 삽입
        int appleCount = std::rand() % 5; // 최대 4번까지 삽입
        for (int j = 0; j < appleCount; ++j) {
            outputFile << "apple ";
        }

        // 나머지 부분에는 랜덤한 알파벳 삽입
        for (int k = 0; k < (10 - appleCount); ++k) {
            char randomChar = 'a' + std::rand() % 26;
            outputFile << randomChar;
        }

        outputFile << std::endl;
    }

    // 파일 닫기
    outputFile.close();

    return 0;
}
