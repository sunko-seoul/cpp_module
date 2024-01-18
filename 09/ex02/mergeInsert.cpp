// arr를 a, b로 나눠서 받음
// a.second 값(index) 보존하기 위해 복사본 만듬
// 복사본은 현재 index로 초기화
// depth 들어감


#include <vector>
#include <algorithm>
#include <iostream>

static unsigned long long jacobsthal_diff[] = {
		2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
		2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
		1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
		178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
		11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
		366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
		11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
		375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
		6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
		96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
		1537228672809129216u, 3074457345618258432u, 6148914691236516864u
	};

std::vector<std::pair<size_t, size_t>> mergeInsert(std::vector<std::pair<size_t, size_t>> arr, size_t size)
{
	if (size < 2)
		return arr;
	size_t	half = size / 2;
	bool	has_stray = size % 2;

	std::vector<std::pair<size_t, size_t>> a;
	std::vector<std::pair<size_t, size_t>> b;
	size_t cnt = 0;
	for (size_t i = 0; i < half; ++i)
	{
		if (arr[i].first > arr[i + half].first)
		{
			a.push_back(std::make_pair(arr[i].first, cnt));
			b.push_back(std::make_pair(arr[i + half].first, cnt));
		}
		else
		{
			a.push_back(std::make_pair(arr[i + half].first, cnt));
			b.push_back(std::make_pair(arr[i].first, cnt));
		}
		cnt++;
	}
	if (has_stray)
		b.push_back(std::make_pair(arr[arr.size() - 1].first, cnt));

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
	a.push_back(b[0]);
	std::rotate(a.begin(), a.end(), a.end() + 1);
	a[0] = b[0];

	size_t	b_idx = 1;
	size_t	jaco_idx = 0;
	std::vector<std::pair<size_t, size_t>>::iterator iter;
	while (b_idx < b.size())
	{
		for (size_t i = jacobsthal_diff[jaco_idx]; i > 0; i--)
		{
			a.push_back(b[b_idx + i]);
			iter = std::upper_bound(a.begin(), a.end() - 1, b[b_idx + i]);
			std::rotate(iter, a.end(), a.end() + 1);
			*iter = b[b_idx + i];
		}
		b_idx += jaco_idx;
		jaco_idx++;
	}
	return (a);
}

int main(void)
{
	std::vector<std::pair<size_t, size_t>> a;

	a.push_back(std::make_pair(7, 0));
	a.push_back(std::make_pair(2, 1));
	a.push_back(std::make_pair(5, 2));
	a.push_back(std::make_pair(10, 3));
	a.push_back(std::make_pair(9, 4));
	a.push_back(std::make_pair(3, 5));
	a.push_back(std::make_pair(1, 6));
	a.push_back(std::make_pair(8, 7));
	a.push_back(std::make_pair(4, 8));
	a.push_back(std::make_pair(6, 9));

	a = mergeInsert(a, a.size());

	std::cout << a.size() << std::endl;
	for (size_t i = 0; i < a.size(); ++i)
		std::cout << a[i].first << " ";
	std::cout << std::endl;
}
