// arr를 a, b로 나눠서 받음
// a.second 값(index) 보존하기 위해 복사본 만듬
// 복사본은 현재 index로 초기화
// depth 들어감


#include <vector>

std::vector<std::pair<size_t, size_t>> mergeInsert(std::vector<std::pair<size_t, size_t>>& arr, size_t size)
{
	if (size < 2)
		return arr;
	size_t	half = size / 2;
	bool	has_stray = size % 2;

	std::vector<std::pair<size_t, size_t>> a;
	std::vector<std::pair<size_t, size_t>> b;
	for (size_t i = 0; i < half; ++i)
	{
		if (arr[i].first > arr[i + half].first)
		{
			a.push_back(std::make_pair(arr[i].first, i));
			b.push_back(std::make_pair(arr[i + half].first, i + half));
		}
		else
		{
			a.push_back(std::make_pair(arr[i + half].first, i +half));
			b.push_back(std::make_pair(arr[i].first, i));
		}
	}
	std::vector<std::pair<size_t, size_t>> orig_a(a);
	std::vector<std::pair<size_t, size_t>> orig_b(b);
	a = mergeInsert(a, a.size());
	std::vector<std::pair<size_t, size_t>> new_b(b);

	// restore a idx and reset b;
	for (size_t i = 0; i < a.size(); ++i)
	{
		for (size_t j = 0; j < a.size(); ++j)
		{
			if (a[i].first == orig_a[j].first)
			{
				a[i].second = orig_a[j].second; // a의 인덱스를 꼭 복원해줘야 하나? b에게 맞는 자리만 찾아주면 될 것 같은데?
				b[i] = orig_b[orig_a[j].second];
			}
		}
	}


	// 이진 삽입 정렬하면 됨, lower bound 쓰면 된다던데 공부해보기
}
