#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(int argc, char* argv[])
{
	int n, k;
	int *temp, maxTemp = INT_MIN;

	cin >> n >> k;
	temp = new int[n];

	for (int i = 0; i < n; ++i)
		cin >> temp[i];

	// 최댓값을 비교해야 하는 횟수
	// 온도의 수 = 4, 일수 = 2 일 때
	// 3
	n -= k - 1;

	// 3번 최댓값을 비교
	for (int i = 0; i < n; ++i)
	{
		int sumTemp = 0;

		// i 번째부터 i + k - 1 번째 까지의 합을 구한다.
		for (int j = i; j < i + k; ++j)
			sumTemp += temp[j];

		// 최댓값을 갱신
		maxTemp = max(maxTemp, sumTemp);
	}

	cout << maxTemp;

	delete temp;

	return 0;
}
