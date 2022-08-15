#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int main(int argc, char* argv[])
{
	int n, k;
	int maxTemp = INT_MIN, localSum = 0;
	queue<int> que;

	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
	{
		int temp;

		cin >> temp;
		
		// i - k + 1 번째부터 i 번째까지의 합을 저장한다.
		// i = 4, k = 3 일 때
		// 2 번째 ~ 4 번째 까지의 합
		localSum += temp;

		// 입력받은 온도를 큐에 삽입한다.
		// 오래된 원소일수록 front 에 가깝게 위치한다.
		que.push(temp);

		// k 번째부터 최댓값 비교를 시작한다.
		if (k <= i)
		{
			// 최댓값을 갱신한다.
			maxTemp = max(maxTemp, localSum);

			// 가장 오래된 요소를 부분합에서 빼준다.
			localSum -= que.front();

			// 큐에서도 제거한다.
			que.pop();
		}
	}

	cout << maxTemp;

	return 0;
}
