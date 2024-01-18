#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 4, 4, 5, 6};
    int value_to_insert = 3;

    v.push_back(0);

    // Step 1: 값이 삽입될 위치 찾기
    auto insert_pos = std::upper_bound(v.begin(), v.end() - 1, value_to_insert);
    std::rotate(insert_pos, v.end(), v.end() + 1);


    // Step 2: 찾은 위치부터 끝까지의 요소들을 왼쪽으로 회전시키기

    // Step 3: 삽입 위치에 값 삽입
    *insert_pos = value_to_insert;

    // 수정된 벡터 출력
    for (const auto &elem : v) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
