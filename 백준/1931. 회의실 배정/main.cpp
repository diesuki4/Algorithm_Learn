#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int lastTime = 0, answer = 0;
	vector<pair<int, int>> vec;
	// pair 의 vector 는, first 가 같은 경우 second 의 값도 비교하지만,
	// multimap 의 경우, first 의 값만 비교하여 삽입한다.
	//multimap<int, int> mmap;

	cin >> N;
	vec = vector<pair<int, int>>(N);

	for (int i = 0; i < N; ++i)
		cin >> vec[i].second >> vec[i].first;

	sort(vec.begin(), vec.end());

	for (auto it = vec.begin(); it != vec.end(); ++it)	// 종료 시점이 빠른 순으로 순회하면서
		if (lastTime <= it->second)	// 지난 회의 종료 시점과 겹치지 않으면 (회의 시작이 가능하면)
			++answer,	// 회의 시작
			lastTime = it->first;	// 회의 종료 시점 갱신

	cout << answer;

	return 0;
}
