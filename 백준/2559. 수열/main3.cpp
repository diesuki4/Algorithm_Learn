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

		localSum += temp;

		que.push(temp);

		if (k <= i)
		{
			maxTemp = max(maxTemp, localSum);

			localSum -= que.front();
			que.pop();
		}
	}

	cout << maxTemp;

	return 0;
}
