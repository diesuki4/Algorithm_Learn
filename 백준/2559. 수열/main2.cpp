#include <iostream>
#include <algorithm>
#include <climits>
#include <list>

using namespace std;

int main(int argc, char* argv[])
{
	int n, k;
	int maxTemp = INT_MIN;
	// 큐는 `for (int e : queue)` 와 같이 순회가 불가능하므로
	// 리스트를 큐처럼 사용함
	list<int> lst;

	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
	{
		int temp;

		// i 번째 온도를 입력받고
		// 현재 큐의 상태 예시
		// front		[0번째 + 1번째 + 2번째]
		// front + 1	[1번째 + 2번째]
		// rear			[2번째]
		cin >> temp;

		// 그 값을 큐의 모든 원소에 더해준다.
		// 현재 큐의 상태 예시
		// front		[0번째 + 1번째 + 2번째 + 3번째]
		// front + 1	[1번째 + 2번째 + 3번째]
		// rear			[2번째 + 3번째]
		for (int &e : lst)
			e += temp;

		// i 번째 온도를 큐에 삽입한다.
		// 현재 큐의 상태 예시
		// front		[0번째 + 1번째 + 2번째 + 3번째]
		// front + 1	[1번째 + 2번째 + 3번째]
		// front + 2	[2번째 + 3번째]
		// rear			[3번째]
		lst.push_back(temp);

		// 큐의 크기가 k 가 된 시점부터 최댓값 비교를 시작한다.
		if (lst.size() == k)
		{
			// 큐의 front 에는 i - k + 1 번째부터 i 번째까지의 합이 들어있다.
			// i = 4, k = 3 일 때
			// 2 번째 ~ 4 번째 까지의 합
			int sum = lst.front();

			// 최댓값을 갱신한다.
			maxTemp = max(maxTemp, sum);

			// 비교가 끝났으므로 큐에서 제거한다.
			lst.pop_front();
		}
	}

	cout << maxTemp;

	lst.clear();

	return 0;
}
